#include <bits/stdc++.h>
 
using namespace std;
 
long long factorial (long long n) {
    if (n < 2) {
        return 1;
    }
    return n * factorial(n - 1);
}
 
int main () {
    iostream::sync_with_stdio(false), cin.tie(nullptr);
    ifstream cin("num2perm.in");
    ofstream cout("num2perm.out");
    long long n, k;
    cin >> n >> k;
    k++;
    vector<bool> p(n + 1, false);
    vector<int> result(n);
    for (int i = 0; i < n; ++i) {
        long long num = (k - 1) / factorial(n - i - 1) + 1;
        int pos = 0, curr;
        for (curr = 1; curr < p.size(); ++curr) {
            if (!p[curr]) {
                pos++;
            }
            if (num == pos) {
                break;
            }
        }
        result[i] = curr;
        p[curr] = true;
        k = (k - 1) % factorial(n - i - 1) + 1;
    }
    for (auto u : result) {
        cout << u << " ";
    }
    return 0;
}