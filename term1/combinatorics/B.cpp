#include <bits/stdc++.h>

using namespace std;

int main() {
    iostream::sync_with_stdio(false), cin.tie(nullptr);
    ifstream cin("gray.in");
    ofstream cout("gray.out");
    unsigned int n;
    cin >> n;
    n--;
    for (int i = 0; i < (2 << n); ++i) {
        for (int q = n; q >= 0; --q) {
            cout << (((i ^ (i >> 1)) >> q) & 1);
        }
        // Коды Грея легко получаются из двоичных чисел путём
        // побитовой операции «Исключающее ИЛИ» с тем же числом,
        // сдвинутым вправо на один бит и в котором старший
        // разряд заполняется нулём.
        cout << endl;
    }
    return 0;
}
