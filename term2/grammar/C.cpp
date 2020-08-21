#include <iostream>
#include <vector>
#include <map>
#include <set>
 
using namespace std;
 
map<char, vector<string>> ks;
set<char> ans, used_letter;
 
const bool is_b_letter (const char c) {
    return (c >= 'A' && c <= 'Z');
}
 
int main () {
    freopen("useless.in", "r", stdin);
    freopen("useless.out", "w", stdout);
    iostream::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    char s;
    cin >> n >> s;
    used_letter.insert(s);
    for (int i = 0; i < n; ++i) {
        char a;
        string arrow, b;
        cin >> a >> arrow;
        getline(cin, b);
        used_letter.insert(a);
 
        bool terminal = false;
        string new_b = "";
        for (const auto &curr_c : b) {
            if (is_b_letter(curr_c)) {
                new_b += curr_c;
                used_letter.insert(curr_c);
                terminal = true;
            }
        }
        if (!terminal) {
            ans.insert(a);
        }
        ks[a].push_back(new_b);
    }
 
    int curr_size;
    do {
        curr_size = ans.size();
        for (const auto &curr_m : ks) {
            for (const auto &curr_str : curr_m.second) {
                bool check = true;
                for (const auto &curr_c : curr_str) {
                    if (ans.count(curr_c) == 0) {
                        check = false;
                        break;
                    }
                }
                if (check) {
                    ans.insert(curr_m.first);
                    break;
                }
            }
        }
    } while (curr_size < ans.size());
 
    map<char, vector<string>> save;
    for (const auto &curr_m : ks) {
        for (const auto &curr_str : curr_m.second) {
            bool check = ans.count(curr_m.first);
            for (const auto &curr_c : curr_str) {
                if (ans.count(curr_c) == 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                save[curr_m.first].push_back(curr_str);
            }
        }
    }
    ks = save;
    save.clear(), ans.clear();
 
    ans.insert(s);
    do {
        curr_size = ans.size();
        for (const auto &curr_m : ks) {
            if (ans.count(curr_m.first) != 0) {
                for (const auto &curr_str : curr_m.second) {
                    for (const auto &curr_c : curr_str) {
                        if (ans.count(curr_c) == 0) {
                            ans.insert(curr_c);
                        }
                    }
                }
            }
        }
    } while (curr_size < ans.size());
 
    for (const auto &curr_m : ks) {
        for (const auto &curr_str : curr_m.second) {
            bool check = ans.count(curr_m.first);
            for (const auto &curr_c : curr_str) {
                if (ans.count(curr_c) == 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                save[curr_m.first].push_back(curr_str);
            }
        }
    }
    ks = save;
    save.clear(), ans.clear();
 
    for (const auto &curr_c : used_letter) {
        bool check = true;
        for (const auto &curr_m : ks) {
            if (curr_c == curr_m.first) {
                check = false;
                break;
            }
            for (const auto &curr_str : curr_m.second) {
                for (const auto &curr_c_in_str : curr_str) {
                    if (curr_c == curr_c_in_str) {
                        check = false;
                        break;
                    }
                }
                if (!check) {
                    break;
                }
            }
            if (!check) {
                break;
            }
        }
 
        if (check) {
            cout << curr_c << '\n';
        }
    }
    return 0;
}