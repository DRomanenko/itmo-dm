#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;

int main(void) {
    iostream::sync_with_stdio(0), cin.tie(0);
    //ifstream cin("input.in");
    //ofstream cout("output.out");

    int n;
    cin >> n;

    vector<string> tableTrueOrFalse(pow(2, n));
    vector<vector<int>> polinom(1, vector<int> (pow(2, n)));

    for (int i = 0; i < pow(2, n); ++i) {
        cin >> tableTrueOrFalse[i];
        cin >> polinom[0][i];
    }

    for (int i = 1; i < pow(2, n); ++i) {
        polinom.push_back(vector<int> ());
        for (int q = 0; q < pow(2, n) - i; ++q) {
            polinom[i].push_back((polinom[i - 1][q] + polinom[i - 1][q + 1]) % 2);
        }
    }

    for (int i = 0; i < pow(2, n); ++i) {
        cout << tableTrueOrFalse[i] << " " << polinom[i][0] << "\n";
    }

    return 0;
}
