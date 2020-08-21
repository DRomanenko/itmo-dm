#include <bits/stdc++.h>
 
using namespace std;
 
string prevVector (string s) {
    string prev = s;
    for (int i = prev.size() - 1; i >= 0; --i) {
        if (prev[i] == '1') {
            prev[i] = '0';
            i++;
            while (i < prev.size()) {
                prev[i] = '1';
                i++;
            }
            /*if (prev.size() > 1 && prev[0] == '0') {
                string b = "";
                for (int j = 1; j < prev.size(); ++j) {
                    b += prev[j];
                }
                prev = b;
            }*/
            return prev;
        }
    }
    // cout << "-";
}
 
string nextVector (string s) {
    string next = '0' + s;
    if (next[next.size() - 1] == '0') {
        string b = "";
        for (int i = 1; i < next.size(); ++i) {
            b += next[i];
        }
        b[b.size() - 1] = '1';
        return b;
    }
    int b = next.size() - 1;
    while (next[b] == '1') {
        next[b] = '0';
        b--;
    }
    next[b] = '1';
 
    if (next[0] == '0') {
        string b = "";
        for (int i = 1; i < next.size(); ++i) {
            b += next[i];
        }
        return b;
    }
    return next;
}
 
int main () {
    iostream::sync_with_stdio(false), cin.tie(nullptr);
    ifstream cin("nextvector.in");
    ofstream cout("nextvector.out");
    string s;
    cin >> s;
    int count0 = 0, count1 = 0;
    for (auto u : s) {
        if (u == '0') {
            count0++;
        } else {
            count1++;
        }
    }
    if (count0 == s.size()) {
        cout << "-" << endl << nextVector(s);
        return 0;
    }
    if (count1 == s.size()) {
        cout << prevVector(s) << endl << "-";
        return 0;
    }
    cout << prevVector(s) << endl;
    cout << nextVector(s);
    return 0;
}