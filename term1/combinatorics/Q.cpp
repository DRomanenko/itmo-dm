#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
 
int main () {
    iostream::sync_with_stdio(false), cin.tie(nullptr);
    ifstream cin("num2brackets.in");
    ofstream cout("num2brackets.out");
    ll n, k;
    cin >> n >> k;
    k++;
    n *= 2;
    ll bal = 0;
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 2, 0));
    dp[0][0] = 1;
    for (ll i = 1; i <= n; ++i) {
        dp[i][0] = dp[i - 1][1];
        for (ll q = 1; q <= n; ++q) {
            dp[i][q] = dp[i - 1][q - 1] + dp[i - 1][q + 1];
        }
    }
    for (ll i = 0; i < n; ++i) {
        if (k <= dp[n - i - 1][bal + 1]) {
            cout << '(';
            ++bal;
        } else {
            cout << ')';
            k -= dp[n - i - 1][bal + 1];
            --bal;
        }
    }
    return 0;
}