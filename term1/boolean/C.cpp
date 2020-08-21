#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    iostream::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<string> table(n);
    vector<int> sizeF(n);
    for (int i = 0; i < n; ++i) {
        cin >> sizeF[i] >> table[i];
    }
    // хоть одна не является тождественным нулём
    bool check0 = 0;
    for (int i = 0; !check0 && i < n; ++i) {
        if (table[i][0] != '0') {
            check0 = 1;
            break;
        }
    }
    // хоть одна не является тождественной единицой
    bool check1 = 0;
    for (int i = 0; !check1 && i < n; ++i) {
        if (table[i][table[i].size() - 1] != '1') {
            check1 = 1;
            break;
        }
    }
    // хоть одна не является самодвойственной
    bool checkSelfDual = 0;
    for (int i = 0; !checkSelfDual && i < n; ++i) {
        for (int q = 0; !checkSelfDual && q <= table[i].size() / 2; ++q) {
            if (table[i][q] == table[i][table[i].size() - q - 1]) {
                checkSelfDual = 1;
                break;
            }
        }
    }
    // хоть одна не является монотонной
    bool checkMonotone = 0;
    for (int i = 0; !checkMonotone && i < n; ++i) {
        int columnSize = table[i].size(), lineSize = sizeF[i];

        vector<vector<bool>> tableTrueOrFalse (columnSize, vector<bool> (lineSize, 0));
        for (int q = 0; !checkMonotone && q < lineSize; ++q){
            int k = columnSize >> (q + 1), p = 0, c = 0;
            for (int j = k; j < columnSize; ++j) {
                if (p < k) {
                    tableTrueOrFalse[j][q] = 1;
                    p++;
                }
                else if(c < k - 1) {
                    tableTrueOrFalse[j][q] = 0;
                    c++;
                } else {
                    p = 0;
                    c = 0;
                }
            }
        }

        for (int q = 0; !checkMonotone && q < columnSize; ++q) {
            for (int t = q; !checkMonotone && t < columnSize; ++t) {
                bool check = 1;
                for (int j = 0; j < lineSize; ++j) {
                    if (tableTrueOrFalse[q][j] > tableTrueOrFalse[t][j]) {
                        check = 0;
                    }
                }

                if (check && table[i][q] > table[i][t]) {
                    checkMonotone = 1;
                }
            }
        }
    }

    // хоть одна не является линейной
    bool checkLinearity = 0;
    for (int i = 0; !checkLinearity && i < n; ++i) {
        vector<vector<int>> polinom(1, vector<int> (table[i].size()));
        for (int q = 0; q < table[i].size(); ++q) {
            polinom[0][q] = table[i][q] - '0';
        }

        for (int q = 1; q < table[i].size(); ++q) {
            polinom.push_back(vector<int> ());
            for (int t = 0; t < table[i].size() - q; ++t) {
                polinom[q].push_back((polinom[q - 1][t] + polinom[q - 1][t + 1]) % 2);
            }
        }
        for (int q = 0; !checkLinearity && q < table[i].size(); ++q) {
            if (polinom[q][0] == 1 && q != 0 && !(q && !(q & (q - 1)))) {
                checkLinearity = 1;
                break;
            }
        }
    }
    if (check0 && check1 && checkSelfDual && checkMonotone && checkLinearity) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}