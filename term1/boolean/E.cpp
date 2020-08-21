#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int depth = 0;
void findDepth (vector<vector<int>> was, int currentDepth, int v) {
    if (was[v].size() == 0) {
        depth = max(currentDepth, depth);
        return;
    }

    for (int i = 0; i < was[v].size(); ++i) {
        findDepth(was, currentDepth + 1, was[v][i]);
    }
}

int main() {
    iostream::sync_with_stdio(false), cin.tie(nullptr);

    unsigned int n;

    cin >> n;

    vector<vector<int>> numberOfInputs;
    vector<vector<int>> itemNumbers;
    vector<vector<int>> was (n);

    int numberOfFunctionalElements = 0;

    for (int i = 0; i < n; ++i) {
        unsigned int m;
        cin >> m;
        if (m == 0) {
            numberOfFunctionalElements++;
        } else {
            numberOfInputs.emplace_back(0);
            itemNumbers.emplace_back(0);
            for (int q = 0; q < m; ++q) {
                int a;
                cin >> a;
                numberOfInputs[numberOfInputs.size() - 1].push_back(a - 1);
                was[i].push_back(a - 1);
            }
            for (int q = 0; q < pow(2, m); ++q) {
                int a;
                cin >> a;
                itemNumbers[itemNumbers.size() - 1].push_back(a);
            }
        }
    }

    findDepth(was, 0, numberOfFunctionalElements + numberOfInputs.size() - 1);
    cout << depth << endl;

    for (int i = 0; i < pow(2, numberOfFunctionalElements); ++i) {
        vector<int> ans(n);
        int count1 = 0, count2 = 0, count3 = 0;
        for (int q = 0; q < n; ++q) {
            if (was[q].size() == 0) {
                count1++;
                ans[q] = (i >> (numberOfFunctionalElements - count1)) % 2;
            } else {
                count3 = 0;
                for (int t = 0; t < numberOfInputs[count2].size(); ++t) {
                    count3 = 2 * count3 + ans[numberOfInputs[count2][t]];
                }
                ans[q] = itemNumbers[count2][count3];
                count2++;
            }
        }
        cout << ans.back();
    }

    return 0;
}
