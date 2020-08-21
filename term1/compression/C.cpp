#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    iostream::sync_with_stdio(0), cin.tie(0);
    ifstream cin("mtf.in");
    ofstream cout("mtf.out");
    string line;
    cin >> line;
    vector<char> cyclicShifts;
    for (int i = 0; i < 26; ++i) {
        cyclicShifts.push_back('a' + i);
    }
    for (int i = 0; i < line.length(); ++i) {
        int save;
        for (int q = 0; q < line.length(); ++q) {
            if (cyclicShifts[q] == line[i]) {
                save = q;
                break;
            }
        }
        cout << save + 1 << " ";
        string boi = "";
        boi += cyclicShifts[save];
        for (int q = 0; q < cyclicShifts.size(); ++q){
            if (q != save) {
                boi += cyclicShifts[q];
            }
        }
        for (int q = 0; q < cyclicShifts.size(); ++q) {
            cyclicShifts[q] = boi[q];
        }
    }
    return 0;
}
