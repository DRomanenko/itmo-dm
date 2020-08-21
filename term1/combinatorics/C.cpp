#include <bits/stdc++.h>

using namespace std;

int main() {
    iostream::sync_with_stdio(false), cin.tie(nullptr);
    ifstream cin("antigray.in");
    ofstream cout("antigray.out");
    int n;
    cin >> n;
    n--;
    int c = pow(3, n);
    for (int i = 0; i < c; ++i) {
        for (int q = n; q >= 0; --q) {
            cout << (((int)(i / pow(3, q))) % 3);
        }
        cout << endl;
        for (int q = n; q >= 0; --q) {
            cout << ((((int)(i / pow(3, q))) % 3) + 1) % 3;
        }
        cout << endl;
        for (int q = n; q >= 0; --q) {
            cout << ((((int)(i / pow(3, q))) % 3) + 2) % 3;
        }
        cout << endl;
    }
    return 0;
}