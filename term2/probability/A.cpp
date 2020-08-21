#include <iostream>
  
using namespace std;
  
int main () {
    freopen("exam.in", "r", stdin);
    freopen("exam.out", "w", stdout);
    iostream::sync_with_stdio(false), cin.tie(nullptr);
    unsigned int k, n;
    cin >> k >> n;
    double res = 0;
    for (unsigned int i = 0; i < k; ++i) {
        unsigned int p, m;
        cin >> p >> m;
        res += m * p;
    }
    cout << res / n / 100 << '\n';
    return 0;
}