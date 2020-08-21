#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;

int main(void) {
    iostream::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> useless;
    
    set<pair<int, int>> krom;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        if (abs(a) > abs(b)) {
            swap(a, b);
        }
        krom.insert({a, b});
    }
    int setSize = krom.size();
    for (int i = 0; i < setSize; ++i) {
        useless.push_back(*krom.begin());
        krom.erase(krom.begin());
    }
    
    int columnSize = pow(2, n);
    vector<vector<bool>> tableTrueOrFalse (columnSize, vector<bool> (n, 0));
    for (int i = 0; i < n; ++i){
        int k = columnSize / (pow(2, i + 1)), p = 0, c = 0;
        for(int j = k; j < columnSize; ++j) {
            if (p < k) {
                tableTrueOrFalse[j][i] = 1;
                p++;
            }
            else if(c < k - 1) {
                tableTrueOrFalse[j][i]= 0;
                c++;
            } else {
                p = 0;
                c = 0;
            }
        }
    }
    
    for (int i = 0; i < columnSize; ++i) {
        bool result;
        for (int q = 0; q < useless.size(); ++q) {
            bool a, b;
            if (useless[q].first < 0) {
                if (tableTrueOrFalse[i][-useless[q].first - 1]) {
                    a = 0;
                } else {
                    a = 1;
                }
            } else {
                a = tableTrueOrFalse[i][useless[q].first - 1];
            }
            if (useless[q].second < 0) {
                if (tableTrueOrFalse[i][-useless[q].second - 1]) {
                    b = 0;
                } else {
                    b = 1;
                }
            } else {
                b = tableTrueOrFalse[i][useless[q].second - 1];
            }

            if (q == 0) {
                result = a || b;
                continue;
            }
            result = (result) && (a || b);
        }
        if (result) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";

    return 0;
}
