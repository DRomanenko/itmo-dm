#include <iostream>
#include <vector>
#include <set>
 
using namespace std;
 
const int shift = 'a';
 
vector<bool> was;
 
/*** https://clck.ru/FrXVE ***/
bool dfs_isomorphism_check (vector<vector<int>> &transitions_1, set<int> &terminal_states_1,
                            vector<vector<int>> &transitions_2, set<int> &terminal_states_2,
                            int v_1, int v_2) {
    was[v_1] = true;
    if (terminal_states_1.count(v_1) != terminal_states_2.count(v_2)) {
        return false;
    }
 
    for (int i = 'a' - shift; i < 'z' - shift + 1; ++i) {
        if (((transitions_1[v_1][i] == -1) != (transitions_2[v_2][i] == -1)) ||
            ((transitions_1[v_1][i] != -1 && !was[transitions_1[v_1][i]]) &&
             !dfs_isomorphism_check(
                     transitions_1, terminal_states_1,
                     transitions_2, terminal_states_2,
                     transitions_1[v_1][i], transitions_2[v_2][i]))) {
            return false;
        }
    }
    return true;
}
 
int main () {
    freopen("isomorphism.in", "r", stdin);
    freopen("isomorphism.out", "w", stdout);
    int n_1, m_1, k_1;
    cin >> n_1 >> m_1 >> k_1;
    was.resize(n_1, false);
 
    set<int> terminal_states_1;
    for (int i = 0; i < k_1; ++i) {
        int a;
        cin >> a;
        terminal_states_1.insert(--a);
    }
 
    vector<vector<int>> transitions_1(n_1, vector<int>('z' - shift + 1, -1));
    for (int i = 0; i < m_1; ++i) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        transitions_1[a - 1][c - shift] = b - 1;
    }
 
 
    int n_2, m_2, k_2;
    cin >> n_2 >> m_2 >> k_2;
 
    set<int> terminal_states_2;
    for (int i = 0; i < k_2; ++i) {
        int a;
        cin >> a;
        terminal_states_2.insert(--a);
    }
 
    vector<vector<int>> transitions_2(n_2, vector<int>('z' - shift + 1, -1));
    for (int i = 0; i < m_2; ++i) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        transitions_2[a - 1][c - shift] = b - 1;
    }
    cout << (dfs_isomorphism_check(transitions_1, terminal_states_1, transitions_2, terminal_states_2, 0, 0) ?
             "YES" :
             "NO") << '\n';
    return 0;
}