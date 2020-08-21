#include <bits/stdc++.h>
 
using namespace std;
 
int main () {
    iostream::sync_with_stdio(false), cin.tie(nullptr);
    ifstream cin("nextbrackets.in");
    ofstream cout("nextbrackets.out");
    string s;
    cin >> s;
    int begin = 0, end = 0;
    for (int i = s.size() - 1; i > 0; --i) {
        if (s[i] == '(') {
            begin++;
            if (end > begin) {
                break;
            }
        } else {
            end++;
        }
    }
    string ss = "";
    for (int i = 0; i < s.size() - begin - end; ++i) {
        ss += s[i];
    }
    bool check = true;
    for (int i = 0; i < s.size(); i += 2) {
        if (s[i] != '(' || s[i + 1] != ')') {
            check = false;
        }
    }
    if (check) {
        cout << "-" << endl;
        return 0;
    }
 
    ss += ')';
    for (int i = 1; i <= begin; ++i) {
        ss += '(';
    }
    for (int i = 1; i <= end - 1; ++i) {
        ss += ')';
    }
    cout << ss << endl;
    return 0;
}