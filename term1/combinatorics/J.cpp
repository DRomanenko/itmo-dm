#include <bits/stdc++.h>
 
using namespace std;
 
int n;
vector<int> terms;
ofstream out("partition.out");
void split (int t, int s) {
    if (s == n) {
        for (int i = 0; i < t - 1; ++i) {
            out << terms[i] << "+";
        }
        out << terms[t - 1] << endl;
    } else {
        if (s < n) {
            for (int i = 0; i < n; ++i) {
                terms[t] = i + 1;
                if (t == 0) {
                    split(t + 1, s + terms[t]);
                } else {
                    if (terms[t] >= terms[t - 1]) {
                        split(t + 1, s + terms[t]);
                    }
                }
            }
        }
    }
}
 
int main () {
    iostream::sync_with_stdio(false), cin.tie(nullptr);
    ifstream cin("partition.in");
    cin >> n;
    terms.resize(n);
    split(0, 0);
    return 0;
}