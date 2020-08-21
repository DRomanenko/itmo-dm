#include <bits/stdc++.h>
 
using namespace std;
 
int C(int n, int k) {
    if ((n == k) || (k == 0)) {
        return 1;
    }
    if (k == 1) {
        return n;
    }
    return C(n - 1, k) + C(n - 1, k - 1);
}
 
int main () {
    iostream::sync_with_stdio(false), cin.tie(nullptr);
    ifstream cin("choose2num.in");
    ofstream cout("choose2num.out");
    int n, k;
    long long result = 0;
    cin >> n >> k;
    vector<int> a(k + 1);
    a[0] = 0;
    for (int i = 1; i <= k; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= k; ++i) {
        for (int j = a[i - 1] + 1; j <= a[i] - 1; ++j) {
            result += C(n - j, k - i);
        }
    }
    cout << result << endl;
    return 0;
}