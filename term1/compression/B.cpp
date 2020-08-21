#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    iostream::sync_with_stdio(0), cin.tie(0);
    ifstream cin("bwt.in");
    ofstream cout("bwt.out");
    string line;
    cin >> line;
    vector<string> cyclicShifts;
    cyclicShifts.push_back(line);
    for (int i = 1; i < line.length(); ++i) {
        cyclicShifts.push_back("");
        cyclicShifts[i] += cyclicShifts[i - 1][line.length() - 1];
        for (int q = 0; q < line.length() - 1; q++){
            cyclicShifts[i] += cyclicShifts[i - 1][q];
        }
    }
    sort(cyclicShifts.begin(), cyclicShifts.end());
    for (int i = 0; i < line.length(); ++i) {
        cout << cyclicShifts[i][line.length() - 1];
    }

    return 0;
}
