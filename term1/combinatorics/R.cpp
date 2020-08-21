#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
 
int main () {
    iostream::sync_with_stdio(false), cin.tie(nullptr);
    ifstream cin("brackets2num.in");
    ofstream cout("brackets2num.out");
    string s;
    cin >> s;
    int n = 0;
    for (char i : s) {
        if (i == '(') {
            n++;
        }
    }
    n *= 2;
    vector<vector<long long>> d(n + 1, vector<long long> (n + 1, 0));
    d[0][0] = 1;
    for (ll i = 1; i <= n; ++i) {
        d[i][0] = d[i - 1][1];
        for (ll q = 1; q <= n; ++q) {
            d[i][q] = d[i - 1][q - 1] + d[i - 1][q + 1];
        }
    }
    ll result = 0, depth = 0;
    for (ll i = 0; i < n; ++i) {
        if (s[i] == '(') {
            depth++;
        } else {
            result += d[n - i - 1][depth + 1];
            depth--;
        }
    }
    cout << result << endl;
    return 0;
}