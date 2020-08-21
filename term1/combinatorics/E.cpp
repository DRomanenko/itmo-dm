#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    iostream::sync_with_stdio(false), cin.tie(nullptr);
    ifstream cin("telemetry.in");
    ofstream cout("telemetry.out");
    int n, k;
    cin >> n >> k;
    //n--;
    //k--;
    int c = static_cast<int>(pow(k, n));
    vector<vector<int>> gray(c, vector<int> (n));
    for (int i = 0; i < k; ++i) {
        gray[i][n - 1] = i;
    }
    int p = k;
    for (int i = 2; i <= n; ++i) {
        p = p * k;
        for (int q = p / k; q < p; q += p / k) {
            for (int y = q; y < q + p / k; ++y) {
                gray[y] = gray[2 * q - y - 1];
                //cout << 2 * q - y - 1 << endl;
            }
        }
        int o = 0;
        for (int q = 0; q < p; q += p / k) {
            for (int y = q; y < q + p / k; ++y) {
                gray[y][n - i] = o;
            }
            ++o;
        }
    }
 
    for (int i = 0; i < c; ++i) {
        for (int q = 0; q < n; ++q) {
            cout << gray[i][q];
        }
        cout << endl;
    }
    /*
    for (int i = 0; i < c; ++i) {
        if (i % k != 0) {
            for (int q = n; q >= 0; --q) {
                int b = static_cast<int>(pow(k, q));
                cout << (int) ((int) (i ^ (i / k)) / b) % k;
                // cout << ((int)(i ^ (i / k)) / q) % 10;
                //cout << (((i ^ (i >> 1)) >> q) & 1);
            }
            // Коды Грея легко получаются из двоичных чисел путём
            // побитовой операции «Исключающее ИЛИ» с тем же числом,
            // сдвинутым вправо на один бит и в котором старший
            // разряд заполняется нулём.
            cout << endl;
        }
    }*/
    return 0;
}