#include <iostream>
#include <vector>
#include <map>
#include <cstring>
 
using namespace std;
 
map<char, vector<pair<char, char>>> ks;
 
const bool check (const char curr_non_terminal, const int curr_index, const string & word) {
    if (curr_index == word.length()) {
        return (curr_non_terminal == '$');
    } else if (curr_non_terminal == '$') {
        return false;
    }
 
    for (auto curr_vec : ks[curr_non_terminal]) {
        if (curr_vec.first == word[curr_index] && check(curr_vec.second, curr_index + 1, word)) {
            return true;
        }
    }
    return false;
}
 
int main () {
    freopen("automaton.in", "r", stdin);
    freopen("automaton.out", "w", stdout);
    iostream::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    char s;
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        char a;
        string arrow, b;
        cin >> a >> arrow >> b;
        ks[a].push_back({b[0], b.length() != 1 ? b[1] : '$'});
    }
 
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        string word;
        cin >> word;
        cout << (check(s, 0, word) ? "yes\n" : "no\n");
    }
    return 0;
}