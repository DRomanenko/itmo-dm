#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    iostream::sync_with_stdio(false), cin.tie(nullptr);
    ifstream cin("allvectors.in");
    ofstream cout("allvectors.out");
    unsigned int n;
    cin >> n;
    n--;
    for (int i = 0; i < (2 << n); ++i) {
        for (int q = n; q >= 0; --q) {
            cout << ((i >> q) & 1);
        }
        cout << endl;
    }
    return 0;
}