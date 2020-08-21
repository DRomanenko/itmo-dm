#include <bits/stdc++.h>

using namespace std;

size_t max(size_t a, size_t b) {
    if (a > b)
        return a;
    return b;
}

unsigned int maxx = 0, saveMaxx = 0;

unsigned int negative (unsigned int curr) {
    for (int i = saveMaxx; i >= 0; --i) {
        curr ^= (1 << i);
    }
    return curr;
}

int main() {
    iostream::sync_with_stdio(false), cin.tie(nullptr);

    unsigned int n;
    cin >> n;

    vector<unsigned int> a (n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    unsigned int s;
    cin >> s;
    unsigned int save_s = s;

    if (s == 0) {
        cout << "1&~1";
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        maxx = max(maxx, a[i]);
    }
    for (unsigned int i = 31; i >= 0; --i) {
        if ((maxx >> i) & 1) {
            saveMaxx = i;
            break;
        }
    }

    vector<int> save;
    /*
    cout << negative(1) << endl;
    cout << negative(2) << endl;
    cout << negative(4) << endl;
    */
    int k = 0;
    string ans = "";
    while (s != 0) {
        if (s <= (unsigned int)(1 << 31) && s & 1) {
            int count = 0;
            for (int i = 0; i < n; ++i) {
                if (!((a[i] >> k) & 1)) {
                    count++;
                }
            }
            if (count == n) {
                cout << "Impossible";
                return 0;
            }
        }
        if (s & 1) { // значение k - того бита
            ans += "(";
            for (int i = 0; i < n; ++i) {
                bool check = false;
                if (a[i] >> k & 1) {
                    ans += (char)(i + '1');
                    save.push_back(i + 1);
                    check = true;
                }
                if (negative(a[i]) >> k & 1) {
                    ans += "~";
                    ans += (char)(i + '1');
                    save.push_back(-(i + 1));
                    check = true;
                }
                if (check && i != n - 1) {
                    ans += "&";
                }
            }
            ans += ")";
        }
        if (s >> 1 && s & 1) {
            ans += "|";
        }
        k++;
        s = s >> 1;
    }

    /*cout << ans << endl;
    for (int i = 0; i < save.size(); ++i) {
        cout << save[i] << " ";
    }
    cout << endl;*/
    /*for (int i = 0; i < saveSize.size(); ++i) {
        cout << saveSize[i] << " ";
    }
    cout << endl;*/

    unsigned int result = 0;
    for (int i = 0; i < save.size(); ++i) {
        unsigned int curr_result = 4294967295;
        for (int q = i; q < n + i; ++q) {
            if (save[q] > 0) {
                curr_result &= a[q - i];
                //cout << "(" << q - i << ":" << a[q - i] << ")" << save[q] << "\n";
            } else {
                curr_result &= negative(a[q - i]);
                //cout << "(" << q - i << "-:-" << negative(a[q - i]) << ")" << save[q] << "\n";
            }
        }
        i += n - 1;
        //cout << endl;
        //i += saveSize[i];
        result |= curr_result;
        //cout << curr_result << endl;
    }
    //cout << result << endl;
    if (result == save_s) {
        cout << ans;
    } else {
        cout << "Impossible";
    }
    return 0;
}
