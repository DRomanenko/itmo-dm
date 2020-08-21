#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
 
ofstream out("part2sets.out");
 
unsigned int n, k;
vector<int> terms;
void split (int s, int t) {
    if (t == n) {
        if (s != k) {
            return;
        }
        vector<vector<int>> a (k);
        for (int i = 0; i < n; ++i) {
            a[terms[i]].push_back(i + 1);
        }
        for (auto i : a) {
            for (auto q : i) {
                out << q << " ";
            }
            out << endl;
        }
        out << endl;
    } else {
        for (int i = 0; i < s; ++i) {
            terms[t] = i;
            split(s, t + 1);
        }
        terms[t] = s;
        split(s + 1, t + 1);
    }
}
 
int main () {
    iostream::sync_with_stdio(false), cin.tie(nullptr);
    ifstream cin("part2sets.in");
    cin >> n >> k;
    terms.resize(n + 1);
    split(0, 0);
    return 0;
}