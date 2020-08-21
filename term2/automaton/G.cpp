#include <iostream>
#include <vector>
#include <set>
#include <queue>
 
using namespace std;
 
const int shift = 'a';
 
int main () {
    freopen("equivalence.in", "r", stdin);
    freopen("equivalence.out", "w", stdout);
    int n_1, m_1, k_1;
    cin >> n_1 >> m_1 >> k_1;
 
    set<int> terminal_states_1;
    for (int i = 0; i < k_1; ++i) {
        int a;
        cin >> a;
        terminal_states_1.insert(a);
    }
 
    vector<vector<int>> transitions_1(n_1 + 1, vector<int>('z' - shift + 1, 0));
    for (int i = 0; i < m_1; ++i) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        transitions_1[a][c - shift] = b;
    }
 
 
    int n_2, m_2, k_2;
    cin >> n_2 >> m_2 >> k_2;
 
    set<int> terminal_states_2;
    for (int i = 0; i < k_2; ++i) {
        int a;
        cin >> a;
        terminal_states_2.insert(a);
    }
 
    vector<vector<int>> transitions_2(n_2 + 1, vector<int>('z' - shift + 1, 0));
    for (int i = 0; i < m_2; ++i) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        transitions_2[a][c - shift] = b;
    }
 
    /*** https://clck.ru/FrcpU ***/
    vector<vector<bool>> was(1001, vector<bool> (1001, false));
    queue<pair<int, int>> p;
    p.push({1, 1});
    while (!p.empty()) {
        int v_1 = p.front().first, v_2 = p.front().second;
        p.pop();
        if (terminal_states_1.count(v_1) != terminal_states_2.count(v_2)) {
            cout << "NO\n";
            return 0;
        }
        was[v_1][v_2] = true;
        for (int i = 'a' - shift; i < 'z' - shift + 1; ++i) {
            if (!was[transitions_1[v_1][i]][transitions_2[v_2][i]]) {
                p.push({transitions_1[v_1][i], transitions_2[v_2][i]});
            }
        }
    }
    cout << "YES\n";
    return 0;
}