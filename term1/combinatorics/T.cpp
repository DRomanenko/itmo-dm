#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
 
int main () {
    iostream::sync_with_stdio(false), cin.tie(nullptr);
    ifstream cin("brackets2num2.in");
    ofstream cout("brackets2num2.out");
    string s;
    cin >> s;
    unsigned int n = 0;
    for (char i : s) {
        if (i == '(' || i == '[') {
            n++;
        }
    }
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
    stack<char> help;
    ll result = 0, depth = 0;
    for (ll i = 0; i < n; ++i) {
        if (s[i] == '(') {
            depth++;
            help.push('(');
        }
        if (depth < n / 2) {
            result += d[n - i - 1][depth + 1] * (1 << ((n - i - 1 - (depth + 1)) >> 1));
        }
        if (s[i] == ')') {
            depth--;
            help.pop();
        }
        if (!help.empty() && help.top() == '(' && depth > 0) {
            result += d[n - i - 1][depth - 1] * (1 << ((n - i - 1 - (depth - 1)) >> 1));
        }
        if (s[i] == '[') {
            depth++;
            help.push('[');
        }
        if (depth < n / 2) {
            result += d[n - i - 1][depth + 1] * (1 << ((n - i - 1 - (depth + 1)) >> 1));
        }
        if (s[i] == ']') {
            depth--;
            help.pop();
        }
    }
    cout << result << endl;
    return 0;
}