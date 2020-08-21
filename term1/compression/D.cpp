#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    iostream::sync_with_stdio(0), cin.tie(0);
    ifstream cin("lzw.in");
    ofstream cout("lzw.out");
    string line;
    cin >> line;
    vector<string> dictionary;
    for (int i = 0; i < 26; ++i) {
        dictionary.push_back("");
        dictionary[i] += 'a' + i;
    }
    string t = "";
    for (int i = 0; i < line.length(); ++i) {
        char c = line[i];
        string tc = t + c;
        bool check = 0;
        for (int q = 0; q < dictionary.size(); ++q) {
            if (dictionary[q] == tc) {
                check = 1;
                t = tc;
            }
        }
        if (!check) {
            int save = 0;
            for (int q = 0; q < dictionary.size(); ++q) {
                if (dictionary[q] == t) {
                    save = q;
                    break;
                }
            }
            dictionary.push_back(tc);
            t = c;
            cout << save << " ";
        }
    }
    if (t != "") {
        int save = 0;
        for (int q = 0; q < dictionary.size(); ++q) {
            if (dictionary[q] == t) {
                save = q;
                break;
            }
        }
        cout << save << " ";
    }

    return 0;
}
