#include <iostream>
#include <vector>
#include <map>
#include <set>
 
using namespace std;
 
map<char, vector<pair<string, bool>>> ks;
set<char> ans;
 
const bool is_s_letter (const char c) {
    return (c >= 'a' && c <= 'z');
}
 
const bool is_b_letter (const char c) {
    return (c >= 'A' && c <= 'Z');
}
 
int main () {
    freopen("epsilon.in", "r", stdin);
    freopen("epsilon.out", "w", stdout);
    iostream::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    char s;
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        char a;
        string arrow, b;
        cin >> a >> arrow;
        getline(cin, b);
 
        bool terminal = true;
        string new_b = "";
        for (const auto &curr_c : b) {
            if (terminal && is_s_letter(curr_c)) {
                terminal = false;
            }
            if (is_b_letter(curr_c)) {
                new_b += curr_c;
            }
        }
        ks[a].push_back({new_b, terminal});
    }
 
    int curr_size;
    do {
        curr_size = ans.size();
        for (char i = 'A'; i <= 'Z'; ++i) {
            for (const auto &curr : ks[i]) {
                bool check = curr.second;
                for (const auto &curr_c : curr.first) {
                    check &= ans.count(curr_c);
                }
                if (check) {
                    ans.insert(i);
                    break;
                }
            }
        }
    } while (curr_size < ans.size());
 
    for (const auto &curr : ans) {
        cout << curr << '\n';
    }
    return 0;
}