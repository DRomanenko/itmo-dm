#include <iostream>
#include <vector>
 
using namespace std;
 
int main () {
    freopen("problem1.in", "r", stdin);
    freopen("problem1.out", "w", stdout);
    string word;
    cin >> word;
 
    int n, m, k;
    cin >> n >> m >> k;
 
    int terminal_states[k];
    for (int i = 0; i < k; ++i) {
        cin >> terminal_states[i];
    }
 
    vector<vector<int>> transitions(n, vector<int> ('z' + 1, -1));
    for (int i = 0; i < m; ++i) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        transitions[a - 1][c] = b - 1;
    }
 
    /*** Check whether you can reach the end of the word on this DFA ***/
    int curr_state = 0;
    for (auto curr_letter : word) {
        if (transitions[curr_state][curr_letter] == -1) {
            cout << "Rejects\n";
            return 0;
        }
        curr_state = transitions[curr_state][curr_letter];
    }
 
    /*** If we are finished in a terminal state. ***/
    for (auto curr_terminal_state : terminal_states) {
        if (curr_state == curr_terminal_state - 1) {
            cout << "Accepts\n";
            return 0;
        }
    }
    cout << "Rejects\n";
    return 0;
}