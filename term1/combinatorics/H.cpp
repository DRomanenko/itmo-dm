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
 
int C(int n, int k) {
    if ((n == k) || (k == 0)) {
        return 1;
    }
    if (k == 1) {
        return n;
    }
    return C(n - 1, k) + C(n - 1, k - 1);
}
 
int main() {
    iostream::sync_with_stdio(false), cin.tie(nullptr);
    ifstream cin("choose.in");
    ofstream cout("choose.out");
    int n, k;
    cin >> n >> k;
    vector<int> c(k);
    for (int i = 0; i < k; ++i) {
        c[i] = i + 1;
    }
    for (int i = 0; i < C(n, k); ++i) {
        for (int q = 0; q < k; ++q) {
            cout << c[q] << " ";
        }
        cout << endl;
        nextC(c, n, k);
    }
    return 0;
}