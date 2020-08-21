#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    iostream::sync_with_stdio(false), cin.tie(nullptr);
    ifstream cin("permutations.in");
    ofstream cout("permutations.out");
    unsigned int n;
    cin >> n;
    vector<int> permutations(n);
    for (int i = 0; i < n; ++i) {
        permutations[i] = i + 1;
    }
    do {
        for (int i = 0; i < n; ++i) {
            cout << permutations[i] << ' ';
        }
        cout << endl;
    } while (next_permutation(permutations.begin(), permutations.end()));
    return 0;
}