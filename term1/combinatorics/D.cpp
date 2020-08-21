#include <bits/stdc++.h>

using namespace std;

int main() {
    iostream::sync_with_stdio(false), cin.tie(nullptr);
    ifstream cin("chaincode.in");
    ofstream cout("chaincode.out");
    unsigned int n;
    cin >> n;
    n--;
    vector<string> chain(2 << n, "");
    vector<int> check(2 << n + 1, 0);
    for (int q = n; q >= 0; --q) {
        chain[0] += '0';
    }
    check[0] = 1;
    cout << chain[0] << endl;
    for (int i = 1; i < (2 << n); ++i) {
        string a = "";
        int result = 0;
        for (int q = 1; q < chain[i - 1].size(); ++q) {
            a += chain[i - 1][q];
            result += ((chain[i - 1][q] - '0') * (2 << (n - q)));
        }
        string b = a;
        a += '1';
        b += '0';
        result += 1;
        if (check[result]) {
            check[--result] = 1;
            chain[i] = b;
            cout << b << endl;
        } else {
            check[result] = 1;
            chain[i] = a;
            cout << a << endl;
        }
    }
    return 0;
}