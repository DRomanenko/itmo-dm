#include <iostream>
 
using namespace std;
 
int main () {
    freopen("lottery.in", "r", stdin);
    freopen("lottery.out", "w", stdout);
    iostream::sync_with_stdio(false), cin.tie(nullptr);
    unsigned int n, m;
    cin >> n >> m;
    double result = 0, previous_result = 0, all = 1;
    for (unsigned int i = 0; i < m; ++i) {
        double a, b;
        cin >> a >> b;
        result += (1 - 1 / a) * previous_result / all;
        previous_result = b;
        all *= a;
    }
    result += previous_result / all;
    cout.precision(13);
    cout << n - result << '\n';
    return 0;
}