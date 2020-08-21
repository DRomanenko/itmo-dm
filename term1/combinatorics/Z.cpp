#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
 
//ofstream out("part2sets.out");
 
int main () {
    iostream::sync_with_stdio(false), cin.tie(nullptr);
    ifstream cin("nextsetpartition.in");
    ofstream cout("nextsetpartition.out");
    int n, k;
    cin >> n >> k;
    while (n != 0) {
        vector<vector<int>> partition(k);
        for (int i = 0; i < k; ++i) {
            string s;
            getline(cin, s);
            if (s.empty()) {
                i--;
                continue;
            }
            int res = 0;
            for (int q = 0; q <= s.size(); ++q) {
                if (s[q] != ' ' && q < s.size()) {
                    res = 10 * res + s[q] - '0';
                } else {
                    partition[i].push_back(res);
                    res = 0;
                }
            }
        }
        vector<int> newValue;
        bool check = false;
        for (int i = k - 1; !check && i >= 0; --i) {
            if (!newValue.empty()) {
                int value = static_cast<int>(2 * 1e9), index = -1;
                for (int q = 0; q < newValue.size(); ++q) {
                    if (newValue[q] < value && newValue[q] > partition[i].back()) {
                        value = newValue[q];
                        index = q;
                    }
                }
                if (index != -1) {
                    partition[i].push_back(value);
                    newValue.erase(newValue.begin() + index);
                    break;
                }
            }
            for (int j = partition[i].size() - 1; j >= 0; --j) {
                if (!newValue.empty() && j != 0) {
                    int value = static_cast<int>(2 * 1e9), index = -1;
                    for (int q = 0; q < newValue.size(); ++q) {
                        if (newValue[q] < value && newValue[q] > partition[i][j]) {
                            value = newValue[q];
                            index = q;
                        }
                    }
                    if (index != -1) {
                        newValue.erase(newValue.begin() + index);
                        newValue.push_back(partition[i][j]);
                        partition[i][j] = value;
                        check = true;
                        break;
                    }
                }
                newValue.push_back(partition[i][j]);
                partition[i].erase(partition[i].begin() + j);
                if (partition[i].empty()) {
                    k--;
                }
            }
        }
 
        sort(newValue.begin(), newValue.end());
        for (auto u : newValue) {
            if (k == partition.size()) {
                partition.emplace_back(0);
            }
            partition[k++].push_back(u);
        }
 
        cout << n << " " << k << endl;
        for (int i = 0; i < k; ++i) {
            for (auto u : partition[i]) {
                cout << u << " ";
            }
            cout << endl;
        }
        cout << endl;
 
        cin >> n >> k;
    }
    return 0;
}