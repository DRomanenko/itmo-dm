#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    ifstream cin("num2choose.in");
    ofstream cout("num2choose.out");
    ll n, k, p, c = -1;
    cin >> n >> k >> p;
    vector<vector<long long>> dp(n, vector<long long> (k + 1, 0));
    for(int i = 0; i < n; ++i)
        dp[i][1] = 1;
    for(int len = 2; len <= k; ++len){
        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j){
                dp[i][len] += dp[j][len - 1];
            }
        }
    }
    ++p;
    for(int i = 0; i < k; ++i){
        ll save = dp[c + 1][k - i], count = c + 1;
        while(save < p){
            count++;
            save += dp[count][k - i];
        }
        c = count;
        cout << c + 1 << " ";
        p = p + dp[c][k - i] - save;
    }
    return 0;
}