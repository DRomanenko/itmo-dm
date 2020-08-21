#include <iostream>
#include <vector>
#include <map>
#include <set>
 
using namespace std;
 
string word;
map<char, vector<string>> ks;
vector<vector<vector<int>>> dp;
 
const bool is_s_letter (const char c) {
    return (c >= 'a' && c <= 'z');
}
 
const bool is_b_letter (const char c) {
    return (c >= 'A' && c <= 'Z');
}
 
const bool is_letter (const char c) {
    return is_s_letter(c) || is_b_letter(c);
}
 
/*** https://clck.ru/FyVsR ***/
int check (int v, int l, int r) {
    /// Check for cycles
    if (dp[v][l][r] == -2 || l >= r) {
        return 0;
    }
 
    /// Check visit
    if (dp[v][l][r] == -1) {
        int res = 0;
        dp[v][l][r] = -2;
 
        for (auto const &curr_str : ks[v]) {
            if (curr_str.length() == 1) {
                res = (is_s_letter(curr_str[0]) ? ((l + 1 == r && word[l] == curr_str[0]) ? 1 : res) : (res | check(
                        curr_str[0], l, r)));
            }
            if (curr_str.length() == 2) {
                if (is_s_letter(curr_str[0]) && is_s_letter(curr_str[1])) {
                    res = ((l + 2 == r && word[l] == curr_str[0] && word[l + 1] == curr_str[1]) ? 1 : res);
                } else if (is_s_letter(curr_str[0])) {
                    res |= (word[l] == curr_str[0] ? check(curr_str[1], l + 1, r) : res);
                } else if (is_s_letter(curr_str[1])) {
                    res |= (word[r - 1] == curr_str[1] ? check(curr_str[0], l, r - 1) : res);
                } else {
                    for (int i = l + 1; i < r; ++i) {
                        res |= check(curr_str[0], l, i) * check(curr_str[1], i, r);
                    }
                }
            }
 
        }
        dp[v][l][r] = res;
    }
 
    return dp[v][l][r];
}
 
int main () {
    freopen("cf.in", "r", stdin);
    freopen("cf.out", "w", stdout);
    iostream::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    char s;
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        char a;
        string arrow, b;
        cin >> a >> arrow;
        getline(cin, b);
 
        string new_b = "";
        for (const auto &curr_c : b) {
            if (is_letter(curr_c)) {
                new_b += curr_c;
            }
        }
        ks[a].push_back(new_b);
    }
 
    /*** https://clck.ru/FyVt8 ***/
 
    /*** 1. Remove the long rules. ***/
    char count = 0;
    map<char, vector<string>> save;
    for (const auto &curr_m : ks) {
        for (const auto &curr_str : curr_m.second) {
            if (curr_str.length() <= 2) {
                save[curr_m.first].push_back(curr_str);
            } else {
                int q = curr_m.first;
                for (int i = 0; i < curr_str.length() - 2; ++i) {
                    save[q].push_back({curr_str[i], ++count});
                    q = count;
                }
                save[q].push_back(curr_str.substr(curr_str.length() - 2, 2));
            }
        }
    }
    ks = save;
    save.clear();
 
    /*** 2.1 Find the ε rules. ***/
    int curr_size;
    set<char> help;
    do {
        curr_size = help.size();
        for (const auto &curr_m : ks) {
            for (const auto &curr_str : curr_m.second) {
                bool check = true;
                for (const auto &curr_c : curr_str) {
                    check = (!is_s_letter(curr_c) && help.count(curr_c));
                    if (!check) {
                        break;
                    }
                }
                if (check) {
                    help.insert(curr_m.first);
                    break;
                }
            }
        }
    } while (curr_size < help.size());
 
    /*** 2(Remove the ε rules) - 5. ***/
    for (const auto &curr_m : ks) {
        for (const auto &curr_str : curr_m.second) {
            if (curr_str.length() == 1) {
                save[curr_m.first].push_back(curr_str);
            }
            if (curr_str.length() == 2) {
                save[curr_m.first].push_back(curr_str);
                if (!is_s_letter(curr_str[0]) && help.count(curr_str[0])) {
                    save[curr_m.first].push_back({curr_str[1]});
                }
                if (!is_s_letter(curr_str[1]) && help.count(curr_str[1])) {
                    save[curr_m.first].push_back({curr_str[0]});
                }
            }
        }
    }
    if (help.count(s)) {
        save['~'].push_back({s});
        save['~'].push_back({{}});
        s = '~';
    }
    ks = save;
    save.clear();
 
    cin >> word;
 
    dp.assign(256, vector<vector<int>>(word.size() + 1, vector<int>(word.size() + 1, -1)));
    cout << (check(s, 0, word.length()) ? "yes\n" : "no\n");
    /*
    4 S
    S -> aAbA
    A -> TB
    B ->
    T ->
    ab
 
    4 S
    S -> aAbAc
    A -> TB
    B ->
    T ->
    ab
    */
 
    //cout << (dp[s][0][word.size()] ? "yes\n" : "no\n");
    /*for (int i = 0; i < 200; ++i) {
        cout << (char)i << " : ";
        for (int q = 0; q < word.size() + 1; ++q) {
            for (int t = 0; t < word.size() + 1; ++t) {
                if (dp[i][q][t] != -1) {
                    cout << dp[i][q][t] << ' ';
                }
            }
        }
        cout << '\n';
    }
    cout << '\n';*/
    return 0;
}