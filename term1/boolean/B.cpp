#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    iostream::sync_with_stdio(0), cin.tie(0);

    unsigned int n, k;

    cin >> n >> k;

    vector<vector<int>> horn (k, vector<int> (n));
    vector<int> table (n, -1);
    vector<bool> checker (n, 0);

    for (int i = 0; i < k; ++i) {
        for (int q = 0; q < n; ++q) {
            cin >> horn[i][q];
        }
    }

    while (true) {
        bool check = false;
        int count = 0;

        /// нахождение всех, одиночностоящий элементов, запоминание их значений
        for (int i = 0; i < k; ++i) {
            if (checker[i]) {
                continue;
            }
            
            int countt = 0, save = 0;

            for (int q = 0; q < n; ++q) {
                if (horn[i][q] > -1) {
                    countt++;
                    save = q;
                }
            }

            if (countt == 1) {
                if (table[save] > -1 && table[save] != horn[i][save]) {
                    /// конъюнкция одиночных элементов дала 0, значит дальше не нужно продолжать
                    cout << "YES";
                    return 0;
                }
                table[save] = horn[i][save];
                check = true;
                count++;
            }
        }
        /// нет одиночностоящих переменных, значит булевую функцию можно разрешить подставив
        /// все 0
        if (!check) {
            cout << "NO";
            return 0;
        }
        for (int i = 0; i < k; ++i) {
            if (checker[i]) {
                continue;
            }
            bool check1 = 0, check2 = 0;
            for (int q = 0; q < n; ++q) {
                if (table[q] == horn[i][q] && horn[i][q] > -1) {
                    check1 = 1;
                }
                if (table[q] < 0 && horn[i][q] > -1) {
                    check2 = 1;
                }
                /// удаление элемента, т.к. он уже просмотрен
                if (horn[i][q] > -1 && table[q] > -1) {
                    horn[i][q] = -1;
                }
            }
            if (!check1 && !check2) {
                cout << "YES";
                return 0;
            }
            if (check1) {
                checker[i] = true;
            }
        }
    }
    return 0;
}
