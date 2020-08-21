#include <bits/stdc++.h>
 
using namespace std;
 
void nextC(vector<int> & a, int n, int k) {
    for (int i = k - 1; i >= 0; --i) {
        if (a[i] < n - k + i + 1) {
            ++a[i];
            for (int q = i + 1; q < k; ++q) {
                a[q] = a[q - 1] + 1;
            }
            return;
        }
    }
}
 
int main() {
    iostream::sync_with_stdio(false), cin.tie(nullptr);
    ifstream cin("nextchoose.in");
    ofstream cout("nextchoose.out");
    int n, k;
    cin >> n >> k;
    vector<int> c(k);
    vector<int> a(k);
    for (int i = 0; i < k; ++i) {
        cin >> c[i];
    }
    a = c;
    nextC(c, n, k);
    if (a != c) {
        for (auto i : c) {
            cout << i << " ";
        }
    } else {
        cout << -1;
    }
    return 0;
}