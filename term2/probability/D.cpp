#include <iostream>
#include <vector>
 
using namespace std;
 
double abss (double a) {
    return a > 0 ? a : -a;
}
 
int main () {
    freopen("markchain.in", "r", stdin);
    freopen("markchain.out", "w", stdout);
    iostream::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<double>> m_c_matrix(n, vector<double>(n));
    for (unsigned int i = 0; i < n; ++i) {
        for (unsigned int q = 0; q < n; ++q) {
            cin >> m_c_matrix[i][q];
        }
    }
    unsigned int count = 0;
    vector<vector<double>> calculation(n, vector<double>(n, 0));
    do {
        count = 0;
        for (unsigned int i = 0; i < n; ++i) {
            for (unsigned int q = 0; q < n; ++q) {
                calculation[i][q] = 0;
                for (unsigned int k = 0; k < n; ++k) {
                    calculation[i][q] += m_c_matrix[i][k] * m_c_matrix[k][q];
                }
            }
        }
        for (unsigned int i = 0; i < n; ++i) {
            for (unsigned int q = 0; q < n; ++q) {
                if (abss(m_c_matrix[i][q] - calculation[i][q]) < 1e-5) {
                    count++;
                }
                m_c_matrix[i][q] = calculation[i][q];
            }
        }
    } while (count != n * n);
    cout.precision(5);
    for (unsigned int i = 0; i < n; ++i) {
        cout << m_c_matrix[0][i] << '\n';
    }
    return 0;
}