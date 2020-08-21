#include <bits/stdc++.h>
 
using namespace std;
 
int main () {
    iostream::sync_with_stdio(false), cin.tie(nullptr);
    ifstream cin("nextperm.in");
    ofstream cout("nextperm.out");
    unsigned int n;
    cin >> n;
    vector<int> array(n), array1(n), array2(n);
    vector<int> arrayCheck1(n), arrayCheck2(n);
    for (int i = 0; i < n; ++i) {
        cin >> array[i];
        arrayCheck1[i] = i + 1;
        arrayCheck2[i] = n - i;
    }
    array1 = array2 = array;
    prev_permutation(array1.begin(), array1.end());
    next_permutation(array2.begin(), array2.end());
    if (n == 1) {
        cout << 0 << endl << 0 << endl;
        return 0;
    }
    if (array1 == arrayCheck2) {
        for (int i = 0; i < n; ++i) {
            cout << 0 << " ";
        }
        cout << endl;
        for (auto u : array2) {
            cout << u << " ";
        }
    } else {
        if (array2 == arrayCheck1) {
            for (auto u : array1) {
                cout << u << " ";
            }
            cout << endl;
            for (int i = 0; i < n; ++i) {
                cout << 0 << " ";
            }
            cout << endl;
        } else {
            for (auto u : array1) {
                cout << u << " ";
            }
            cout << endl;
            for (auto u : array2) {
                cout << u << " ";
            }
        }
    }
 
    return 0;
}