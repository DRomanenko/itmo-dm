#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
 
using namespace std;
 
const int shift = 'a';
 
void dfs (vector<bool> &was, vector<vector<int>> &transitions, int v) {
    if (v == 0) {
        return;
    }
 
    was[v] = true;
    for (auto curr_transition : transitions[v]) {
        if (!was[curr_transition]) {
            dfs(was, transitions, curr_transition);
        }
    }
}
 
int new_n = 0;
vector<pair<int, pair<int, char>>> new_transitions;
 
inline void build_ans (vector<int> &num, vector<vector<int>> &minimal_states, int v) {
    if (num[v] == 0) {
        num[v] = ++new_n;
        for (int c = 'a' - shift; c < 'z' - shift + 1; ++c) {
            if (minimal_states[v][c] != -1) {
                build_ans(num, minimal_states, minimal_states[v][c]);
                new_transitions.push_back({num[v], {num[minimal_states[v][c]], c + 'a'}});
            }
        }
    }
}
 
int main () {
    freopen("minimization.in", "r", stdin);
    freopen("minimization.out", "w", stdout);
    iostream::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    ++n;
 
    set<int> terminal_states;
    for (int i = 0; i < k; ++i) {
        int a;
        cin >> a;
        terminal_states.insert(a);
    }
 
    vector<vector<int>> transition(n, vector<int>('z' - shift + 1, 0));
    for (int i = 0; i < m; ++i) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        transition[a][c - 'a'] = b;
    }
    vector<vector<vector<int>>> reverse_transitions(n, vector<vector<int>>('z' - shift + 1));
    for (int i = 0; i < n; ++i) {
        for (int c = 'a' - shift; c < 'z' - shift + 1; ++c) {
            reverse_transitions[transition[i][c]][c].push_back(i);
        }
    }
 
    vector<bool> was(n, false);
    dfs(was, transition, 1);
     
    /*** https://clck.ru/9wx62 ***/
    vector<int> Class(n, 0);
    set<int> F = terminal_states;
 
    set<int> Q_F; /// Q/F
    for (int i = 0; i < n; ++i) {
        if (F.count(i) == 0) {
            Q_F.insert(i);
            Class[i] = 1;
        }
    }
 
    vector<set<int>> P;
    P.push_back(F), P.push_back(Q_F);
 
    queue<pair<int, int>> queue;
    for (int c = 'a' - shift; c < 'z' - shift + 1; ++c) {
        queue.push({0, c}), queue.push({1, c});
    }
 
    while (!queue.empty()) {
        set<int> C = P[queue.front().first];
        int a = queue.front().second;
        queue.pop();
        map<int, vector<int>> Involved;
        for (auto c : C) {
            for (auto state : reverse_transitions[c][a]) {
                Involved[Class[state]].push_back(state);
            }
        }
 
        for (const auto &i : Involved) {
            if (!i.second.empty()) {
                if (Involved[i.first].size() < P[i.first].size()) {
                    int j = P.size();
                    P.push_back((set<int>) {});
                    for (auto r : Involved[i.first]) {
                        P[i.first].erase(r), P[j].insert(r);
                    }
                    if (P[i.first].size() < P[j].size()) {
                        swap(P[i.first], P[j]);
                    }
                    for (auto r : P[j]) {
                        Class[r] = j;
                    }
                    for (int c = 'a' - shift; c < 'z' - shift + 1; ++c) {
                        queue.push({j, c});
                    }
                }
            }
        }
    }
 
    vector<vector<int>> minimal_states(n, vector<int>('z' - shift + 1, -1));
    for (int i = 0; i < n; ++i) {
        if (was[i] && Class[i] != Class[0] && was[i]) {
            for (int c = 'a' - shift; c < 'z' - shift + 1; ++c) {
                if (was[transition[i][c]] && Class[transition[i][c]] != Class[0]) {
                    minimal_states[Class[i]][c] = Class[transition[i][c]];
                }
            }
        }
    }
    vector<int> num(n, 0);
    build_ans(num, minimal_states, Class[1]);
 
    set<int> new_terminal_states;
    for (auto curr_terminal_state : terminal_states) {
        if (was[curr_terminal_state] && Class[curr_terminal_state] != Class[0]) {
            new_terminal_states.insert(num[Class[curr_terminal_state]]);
        }
    }
 
    cout << new_n << ' ' << new_transitions.size() << ' ' << new_terminal_states.size() << '\n';
    for (auto curr_new_terminal_state : new_terminal_states) {
        cout << curr_new_terminal_state << ' ';
    }
    cout << "\n";
    for (auto curr_new_transition : new_transitions) {
        cout << curr_new_transition.first << ' '
             << curr_new_transition.second.first << ' '
             << curr_new_transition.second.second << '\n';
    }
 
    return 0;
}