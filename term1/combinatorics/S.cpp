#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
 
int main () {
    iostream::sync_with_stdio(false), cin.tie(nullptr);
    ifstream cin("num2brackets2.in");
    ofstream cout("num2brackets2.out");
    ll n, k;
    cin >> n >> k;
    n *= 2;
    vector<vector<ll>> d(n + 1, vector<ll> (n + 1, 0));
    d[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int q = 0; q < n / 2 + 1; ++q) {
            if (q < n) {
                d[i + 1][q + 1] += d[i][q];
            }
            if (q > 0) {
                d[i + 1][q - 1] += d[i][q];
            }
        }
    }
    vector<char> help(n), result;
    ll depth = 0, currElement, currIndex = 0;
    k++;
    for (ll i = n - 1; i >= 0; --i) {
        if (depth < n / 2) {
            currElement = d[i][depth + 1] * (1 << ((i - (depth + 1)) >> 1));
        } else {
            currElement = 0;
        }
        if (currElement >= k) {
            help[currIndex++] = '(';
            result.push_back('(');
            ++depth;
            continue;
        }
        k -= currElement;
        if (currIndex > 0 && help[currIndex - 1] == '(' && depth > 0) {
            currElement = d[i][depth - 1] * (1 << ((i - (depth - 1)) >> 1));
        } else {
            currElement = 0;
        }
        if (currElement >= k) {
            --currIndex;
            --depth;
            result.push_back(')');
            continue;
        }
        k -= currElement;
        if (depth < n / 2) {
            currElement = d[i][depth + 1] * (1 << ((i - (depth + 1)) >> 1));
        } else {
            currElement = 0;
        }
        if (currElement >= k) {
            help[currIndex++] = '[';
            ++depth;
            result.push_back('[');
            continue;
        }
        k -= currElement;
        --currIndex;
        --depth;
        result.push_back(']');
    }
    for (auto u : result) {
        cout << u;
    }
    return 0;
}