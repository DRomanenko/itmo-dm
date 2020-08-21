#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    iostream::sync_with_stdio(false), cin.tie(nullptr);
    ifstream cin("vectors.in");
    ofstream cout("vectors.out");
    unsigned int n;
    cin >> n;
    n--;
    vector<string> save;
    int count = 0;
    bool check = false;
    for (int i = 0; i < (2 << n); ++i) {
        string s = "";
        check = false;
        bool check1 = false;
 
        for (int q = n; q >= 0; --q) {
            if (check && ((i >> q) & 1)) {
                check1 = true;
                break;
            }
            s += ((i >> q) & 1) + '0';
            check = ((i >> q) & 1) != 0;
        }
        if (!check1) {
            count++;
            save.push_back(s);
        }
    }
    cout << count << endl;
    for (const auto &i : save) {
        cout << i << endl;
    }
    return 0;
}