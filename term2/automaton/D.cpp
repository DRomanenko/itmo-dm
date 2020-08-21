#include <iostream>
#include <vector>
#include <set>
 
using namespace std;
 
const int mod(1e9 + 7);
 
int main () {
    freopen("problem4.in", "r", stdin);
    freopen("problem4.out", "w", stdout);
    int n, m, k, l;
    cin >> n >> m >> k >> l;
 
    int terminal_states[k];
    for (int i = 0; i < k; ++i) {
        cin >> terminal_states[i];
    }
 
    vector<vector<int>> transitions(n, vector<int>('z' - 'a' + 1, -1));
    for (int i = 0; i < m; ++i) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        transitions[a - 1][c - 'a'] = b - 1;
    }
 
    /*** Make L transitions and find the number of words for each transition. ***/
    vector<int> sum(n, 1);
    set<int> curr_states;
    curr_states.insert(0);
    for (int i = 0; i < l; ++i) {
        set<int> new_curr_states;
        vector<int> new_sum(n, 0);
        for (auto curr_state : curr_states) {
            for (auto transition : transitions[curr_state]) {
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
        for (auto curr_terminal_state : terminal_states) {
            if (curr_state == curr_terminal_state - 1) {
                res = (res + sum[curr_state]) % mod;
            }
        }
    }
    cout << res << '\n';
    return 0;
}