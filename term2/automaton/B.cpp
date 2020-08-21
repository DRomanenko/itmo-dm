#include <iostream>
#include <vector>
#include <set>
 
using namespace std;
 
int main () {
    freopen("problem2.in", "r", stdin);
    freopen("problem2.out", "w", stdout);
    string word;
    cin >> word;
 
    int n, m, k;
    cin >> n >> m >> k;
 
    int terminal_states[k];
    for (int i = 0; i < k; ++i) {
        cin >> terminal_states[i];
    }
 
    vector<vector<vector<int>>> transitions(n, vector<vector<int>> ('z' + 1));
    for (int i = 0; i < m; ++i) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        transitions[a - 1][c].push_back(b - 1);
    }
 
    /*** Check whether you can reach the end of the word on this NFA. ***/
    set<int> curr_states;
    curr_states.insert(0);
    for (auto curr_letter : word) {
        set<int> new_curr_states;
        for (auto curr_state : curr_states) {
            for (auto transition : transitions[curr_state][curr_letter]) {
                new_curr_states.insert(transition);
            }
        }
 
        if (new_curr_states.empty()) {
            cout << "Rejects\n";
            return 0;
        }
 
        curr_states = new_curr_states;
    }
 
    /*** If we are finished in a terminal state. ***/
    for (auto curr_state : curr_states) {
        for (auto curr_terminal_state : terminal_states) {
            if (curr_state == curr_terminal_state - 1) {
                cout << "Accepts\n";
                return 0;
            }
        }
    }
    cout << "Rejects\n";
    return 0;
}