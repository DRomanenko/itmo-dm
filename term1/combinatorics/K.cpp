#include <bits/stdc++.h>
 
using namespace std;
 
int main () {
    iostream::sync_with_stdio(false), cin.tie(nullptr);
    ifstream cin("subsets.in");
    ofstream cout("subsets.out");
    int n;
    cin >> n;
    vector<string> a;
    for (int i = 0; i < (1 << n); ++i) {
        a.push_back("");
        for (int q = 0; q < n; ++q) {
            if (i & (1 << q)) {
                if (q + 1 == 10) {
                    a[i].push_back('z');
                    a[i].push_back(' ');
                    continue;
                }
                a[i].push_back(q + 1 + '0');
                a[i].push_back(' ');
            }
        }
    }
    sort(a.begin(), a.end());
    for (auto u : a) {
        for (int i = 0; i < u.size(); ++i) {
            if (u[i] == 'z') {
                cout << 10;
                continue;
            }
            cout << u[i];
        }
        cout << endl;
    }
    return 0;
}