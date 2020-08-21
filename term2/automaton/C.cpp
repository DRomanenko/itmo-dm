#include <iostream>
#include <vector>
 
using namespace std;
 
const int mod(1e9 + 7);
vector<bool> useful_states;
 
vector<bool> was;
 
inline void dfs_for_useful_states (vector<vector<vector<int>>> &reverse_transitions, int v) {
    useful_states[v] = true, was[v] = true;
    for (const auto &u : reverse_transitions[v]) {
        for (auto reverse_transition : u) {
            if (!was[reverse_transition]) {
                dfs_for_useful_states(reverse_transitions, reverse_transition);
            }
        }
    }
}
 
vector<short> color;
 
bool dfs_for_cycles (vector<vector<int>> &transitions, int v) {
    color[v] = 1;
    for (auto transition : transitions[v]) {
        if (transition != -1 && useful_states[transition] &&
            ((color[transition] == 0 && dfs_for_cycles(transitions, transition)) || (color[transition] == 1))) {
            return true;
        }
    }
    color[v] = 2;
    return false;
}
 
vector<int> top_sorted_transitions;
 
inline void topological_sort (vector<vector<vector<int>>> &reverse_transitions, int v) {
    was[v] = true;
    for (const auto &u : reverse_transitions[v]) {
        for (auto reverse_transition : u) {
            if (!was[reverse_transition]) {
                topological_sort(reverse_transitions, reverse_transition);
            }
        }
    }
    top_sorted_transitions.push_back(v);
}
 
int main () {
    freopen("problem3.in", "r", stdin);
    freopen("problem3.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
 
    int terminal_states[k];
    useful_states.resize(n, false);
    for (int i = 0; i < k; ++i) {
        cin >> terminal_states[i];
        useful_states[terminal_states[i] - 1] = true;
    }
 
    vector<vector<int>> transitions(n, vector<int>('z' - 'a' + 1, -1));
    vector<vector<vector<int>>> reverse_transitions(n, vector<vector<int>>('z' - 'a' + 1));
    for (int i = 0; i < m; ++i) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        transitions[a - 1][c - 'a'] = b - 1;
        reverse_transitions[b - 1][c - 'a'].push_back(a - 1);
    }
 
    /*** Find all the useful states from which at least one terminal state is reachable. ***/
    was.resize(n, false);
    for (auto curr_terminal_state : terminal_states) {
        dfs_for_useful_states(reverse_transitions, curr_terminal_state - 1);
    }
 
    /*** Find any cycle that is useful, accessible from the start. ***/
    color.resize(n, 0);
    if (dfs_for_cycles(transitions, 0)) {
        /*** Language is infinite! ***/
        cout << "-1\n";
        return 0;
    }
 
    /*** TOP SORT ***/
    was.assign(n, false);
    for (auto curr_terminal_state : terminal_states) {
        if (!was[curr_terminal_state - 1]) {
            topological_sort(reverse_transitions, curr_terminal_state - 1);
        }
    }
 
    /*** Calculate accessory function that specifies the number of different paths. ***/
    was.assign(n, false);
    vector<int> sum(n, 0);
    sum[0] = 1;
    for (auto top_sorted_transition : top_sorted_transitions) {
        for (const auto &b : reverse_transitions[top_sorted_transition]) {
            for (auto reverse_transition : b) {
                sum[top_sorted_transition] = (sum[top_sorted_transition] + sum[reverse_transition]) % mod;
            }
        }
    }
 
    /*** Count the number of words ***/
    int res = 0;
    for (auto curr_terminal_state : terminal_states) {
        res = (res + sum[curr_terminal_state - 1]) % mod;
    }
    cout << res << '\n';
    return 0;
}