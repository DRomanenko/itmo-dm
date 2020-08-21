#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
 
using namespace std;
 
const int mod(1e9 + 7), shift = 'a';
 
int main () {
    freopen("problem5.in", "r", stdin);
    freopen("problem5.out", "w", stdout);
    int n, m, k, l;
    cin >> n >> m >> k >> l;
 
    int terminal_states_for_NFA[k];
    for (int i = 0; i < k; ++i) {
        cin >> terminal_states_for_NFA[i];
    }
 
    vector<vector<vector<int>>> transitions_for_NFA(n, vector<vector<int>>('z' - shift + 1));
    for (int i = 0; i < m; ++i) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        transitions_for_NFA[a - 1][c - 'a'].push_back(b - 1);
    }
 
    vector<vector<int>> transitions_for_DFA(101, vector<int>('z' - shift + 1, -1));
    vector<int> terminal_states_for_DFA;
    for (auto curr_terminal_state : terminal_states_for_NFA) {
        if (curr_terminal_state == 1) {
            terminal_states_for_DFA.push_back(curr_terminal_state - 1);
            break;
        }
    }
 
    /*** Thompson algorithm: Builds DFA equivalent NFA. ***/
    queue<set<int>> p;
    p.push({0});
 
    map<set<int>, int> number_of_states;
    number_of_states[{0}] = 0;
    int count(0);
 
    set<set<int>> check_rest_queue;
    check_rest_queue.insert({0});
 
    while (!p.empty()) {
        set<int> curr_NFA_states = p.front();
        p.pop();
 
        for (int curr_letter = 'a' - shift; curr_letter < 'z' - shift + 1; ++curr_letter) {
            set<int> new_curr_states;
            bool check_terminal = false;
            for (auto curr_NFA_state : curr_NFA_states) {
                for (auto curr_state_NFA : transitions_for_NFA[curr_NFA_state][curr_letter]) {
                    new_curr_states.insert(curr_state_NFA);
                    if (!check_terminal) {
                        for (auto curr_terminal_state : terminal_states_for_NFA) {
                            if (curr_state_NFA == curr_terminal_state - 1) {
                                check_terminal = true;
                                break;
                            }
                        }
                    }
                }
            }
            if (!new_curr_states.empty()) {
                if (!check_rest_queue.count(new_curr_states)) {
                    p.push(new_curr_states);
                    number_of_states[new_curr_states] = ++count;
                    check_rest_queue.insert(new_curr_states);
                    if (check_terminal) {
                        terminal_states_for_DFA.push_back(number_of_states[new_curr_states]);
                    }
                }
                transitions_for_DFA[number_of_states[curr_NFA_states]][curr_letter] = number_of_states[new_curr_states];
            }
        }
    }
 
    /*** Make L transitions and find the number of words for each transition. ***/
    vector<int> sum(101, 1);
    set<int> curr_states;
    curr_states.insert(0);
    for (int i = 0; i < l; ++i) {
        set<int> new_curr_states;
        vector<int> new_sum(101, 0);
        for (auto curr_state : curr_states) {
            for (auto transition : transitions_for_DFA[curr_state]) {
                if (transition != -1) {
                    new_sum[transition] = (new_sum[transition] + sum[curr_state]) % mod;
                    new_curr_states.insert(transition);
                }
            }
        }
        sum = new_sum;
        curr_states = new_curr_states;
    }
 
    /*** Count the number of words of length L, if we are finished in a terminal state. ***/
    int res = 0;
    for (auto curr_state : curr_states) {
        for (auto curr_terminal_state : terminal_states_for_DFA) {
            if (curr_state == curr_terminal_state) {
                res = (res + sum[curr_state]) % mod;
            }
        }
    }
    cout << res << '\n';
    return 0;
}