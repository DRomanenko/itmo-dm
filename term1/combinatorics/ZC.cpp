#include <bits/stdc++.h>
 
using namespace std;
 
int main () {
    iostream::sync_with_stdio(false), cin.tie(nullptr);
    //ifstream cin("nextpartition.in");
    FILE * fin = fopen("nextpartition.in", "r");
    ofstream cout("nextpartition.out");
    int a, b;
    fscanf(fin, "%d=%d", &a, &b);
    if (a == b) {
        cout << "No solution";
        return 0;
    }
    vector<int> split;
    split.push_back(b);
    while (fscanf(fin, "+%d", &b)) {
        split.push_back(b);
    }
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
    cout << a << "=";
    for (int i = 0; i < split.size() - 1; ++i) {
        cout << split[i] << "+";
    }
    cout << split[split.size() - 1];
    fclose(fin);
    /*
    string s;
    cin >> s;
    if ((s.size() & 1)) {
        bool check = true;
        for (int i = 0; i < s.size() / 2; ++i) {
            if (s[i] != s[s.size() / 2 + i]) {
                check = false;
            }
        }
        if (check) {
            cout << "No solution";
            return 0;
        }
    }
    int b = 0;
    vector<int> split;
    for (b = 0; b < s.size(); ++b) {
        if (s[b] == '=') {
            b++;
            break;
        }
    }
    for (int i = b; i < s.size(); ++b) {
        if (s[i] != '+') {
            int ret = 0;
            do {
                ret = ret * 10 + s[i] - '0';
                i++;
            } while (s[i] != '+')
        }
    }
    cout << b;*/
    return 0;
}