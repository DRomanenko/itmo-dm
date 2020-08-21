#include <bits/stdc++.h>
 
using namespace std;
 
void next(vector<int> &split) {
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
    //iostream::sync_with_stdio(false), cin.tie(nullptr);
    //ifstream cin("part2num.in");
    FILE * fin = fopen("part2num.in", "r");
    ofstream cout("part2num.out");
    unsigned int a, sum = 0;
    vector<int> split;
    fscanf(fin, "%d", &a);
    sum += a;
    split.push_back(a);
    while (fscanf(fin, "+%d", &a)) {
        sum += a;
        split.push_back(a);
    }
    vector<int> mask;
    mask.reserve(sum);
    for (int i = 0; i < sum ; ++i) {
        mask.push_back(1);
    }
    long long count = 0;
    while (mask != split) {
        next(mask);
        count++;
    }
    cout << count << endl;
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