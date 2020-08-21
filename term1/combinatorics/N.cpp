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
    ifstream cin("perm2num.in");
    ofstream cout("perm2num.out");
    long long n;
    cin >> n;
    vector<bool> p(n + 1, false);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    long long result = 0;
    for (int i = 0; i < n; ++i) {
        int curr = 1;
        while (curr != a[i]) {
            while (p[curr] && curr < p.size()) {
                curr++;
            }
            if (curr == a[i]) {
                p[curr] = true;
                break;
            }
            curr++;
            result += factorial(n - i - 1);
        }
        p[curr] = true;
    }
    cout << result << endl;
    return 0;
}