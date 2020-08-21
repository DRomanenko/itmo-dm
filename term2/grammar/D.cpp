#include <iostream>
#include <vector>
#include <map>
#include <set>
 
using namespace std;
 
const long long MOD = 1000000007;
 
map<char, vector<string>> ks;
vector<vector<vector<long long>>> dp;
 
int main () {
    freopen("nfc.in", "r", stdin);
    freopen("nfc.out", "w", stdout);
    iostream::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    char s;
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        char a;
        string arrow, b;
        cin >> a >> arrow >> b;
        ks[a].push_back(b);
    }
 
    string word;
    cin >> word;
    dp.assign(26, vector<vector<long long>>(word.size(), vector<long long>(word.size(), 0)));
    for (int i = 0; i < word.size(); ++i) {
        for (const auto &curr_m : ks) {
            for (const auto &curr : curr_m.second) {
                if (curr.length() == 1 && curr[0] == word[i]) {
                    dp[curr_m.first - 'A'][i][i] = 1;
                }
            }
        }
    }
 
    for (int len = 1; len < word.length(); ++len) {
        for (int i = 0; i < word.size() - len; ++i) {
            for (const auto &curr_m : ks) {
                for (const auto &curr_str : curr_m.second) {
                    for (int q = i; q < word.length() - 1; ++q) {
                        if (curr_str.length() > 1) {
                            long long a = (dp[curr_str[0] - 'A'][i][q] * dp[curr_str[1] - 'A'][q + 1][i + len]) % MOD;
                            dp[curr_m.first - 'A'][i][i + len] = (dp[curr_m.first - 'A'][i][i + len] + a) % MOD;
                        }
                    }
                }
            }
        }
    }
    cout << dp[s - 'A'][0][word.size() - 1];
    return 0;
}