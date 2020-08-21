#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
 
 
int main() {
    iostream::sync_with_stdio(false), cin.tie(nullptr);
    ifstream cin("brackets.in");
    ofstream cout("brackets.out");
    int n;
    cin >> n;
    vector<ll> CatalanNumbers(n + 2);
    CatalanNumbers[0] = 1;
    CatalanNumbers[1] = 1;
    for (int i = 2; i < n + 2; ++i) {
        CatalanNumbers[i] = 0;
        for (int j = 0; j < i; ++j) {
            CatalanNumbers[i] += CatalanNumbers[j] * CatalanNumbers[i - j];
        }
    }
    /*
    for (auto i : CatalanNumbers) {
        cout << i << endl;
    }*/
    //cout << CatalanNumbers[n + 1] << endl;
    int Size = CatalanNumbers[n + 1];
    //cout << Size << endl;
    n *= 2;
    for (int o = 1; o <= Size; ++o) {
        int k = o;
        int bal = 0;
        vector<vector<ll>> dp(n + 1, vector<ll>(n + 2, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = dp[i - 1][1];
            for (int q = 1; q <= n; ++q)
                dp[i][q] = dp[i - 1][q - 1] + dp[i - 1][q + 1];
        }
        for (int i = 0; i < n; ++i) {
            if (k <= dp[n - i - 1][bal + 1]) {
                cout << '(';
                ++bal;
            } else {
                cout << ')';
                k -= dp[n - i - 1][bal + 1];
                --bal;
            }
        }
        cout << endl;
    }
    return 0;
}