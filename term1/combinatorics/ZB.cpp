#include <bits/stdc++.h>
 
using namespace std;
 
vector<int> next(vector<int> &split) {
    split[split.size() - 1]--;
    split[split.size() - 2]++;
    if (split[split.size() - 2] > split[split.size() - 1]) {
        split[split.size() - 2] += split[split.size() - 1];
        split.pop_back();
    } else {
        while (2 * split[split.size() - 2] <= split[split.size() - 1]) {
            split.push_back(split[split.size() - 1] - split[split.size() - 2]);
            split[split.size() - 2] = split[split.size() - 3];
        }
    }
}
 
int main () {
    iostream::sync_with_stdio(false), cin.tie(nullptr);
    ifstream cin("nextmultiperm.in");
    //FILE * fin = fopen("nextpartition.in", "r");
    ofstream cout("nextmultiperm.out");
    int n;
    cin >> n;
    vector<int> multiperm(n);
    for (int i = 0; i < n; ++i) {
        cin >> multiperm[i];
    }
    int i = n - 2;
    while (i >= 0 && (multiperm[i] >= multiperm[i + 1])) {
        --i;
    }
    if (i < 0) {
        for (int i = 0; i < n; ++i) {
            cout << 0 << " ";
        }
    } else {
        int j = i + 1;
        while (j < n - 1 && multiperm[j + 1] > multiperm[i]) {
            ++j;
        }
        swap(multiperm[i], multiperm[j]);
        for (int q = 0; q < i + 1; ++q) {
            cout << multiperm[q] << " ";
        }
        for (int q = n - 1; q >= i + 1; --q) {
            cout << multiperm[q] << " ";
        }
    }
    return 0;
}