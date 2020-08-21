#include <bits/stdc++.h>
 
using namespace std;
 
void next(vector<long long> &split) {
    split[split.size() - 1]--;
    split[split.size() - 2]++;
    if (split[split.size() - 2] > split[split.size() - 1]) {
        split[split.size() - 2] += split[split.size() - 1];
        if (!split.empty()) {
            split.pop_back();
        }
    } else {
        while (2 * split[split.size() - 2] <= split[split.size() - 1]) {
            split.push_back(split[split.size() - 1] - split[split.size() - 2]);
            split[split.size() - 2] = split[split.size() - 3];
        }
    }
}
 
int main () {
    iostream::sync_with_stdio(false), cin.tie(nullptr);
    ifstream cin("num2part.in");
    //FILE * fin = fopen("nextpartition.in", "r");
    ofstream cout("num2part.out");
    unsigned int sum, k;
    cin >> sum >> k;
    vector<long long> mask;
    mask.reserve(sum);
    for (int i = 0; i < sum ; ++i) {
        mask.push_back(1LL);
    }
    long long count = 0;
    while (count != k) {
        next(mask);
        count++;
    }
    cout << mask[0];
    for (int i = 1; i < mask.size(); ++i) {
        cout << "+" << mask[i];
    }
    /*
    for (int i = 0; i < sum; ++i) {
        for (auto u : mask) {
            cout << u << " ";
        }
        cout << endl;
        next(mask);
    }*/
    return 0;
}