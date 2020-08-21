#include <iostream>
 
using namespace std;
 
double pow (double p, int m) {
    if (m == 0) {
        return 1;
    }
    return p * pow(p, m - 1);
}
 
int main () {
    freopen("shooter.in", "r", stdin);
    freopen("shooter.out", "w", stdout);
    iostream::sync_with_stdio(false), cin.tie(nullptr);
    unsigned int n, m, k;
    cin >> n >> m >> k;
    double target_shooter = 0, all_shooter = 0;
    for (unsigned int i = 0; i < n; ++i) {
        double p;
        cin >> p;
        if (i == k - 1) {
            target_shooter = pow((1 - p), m);
        }
        all_shooter += pow((1 - p), m);
    }
    cout.precision(13);
    cout << target_shooter / all_shooter << '\n';
    return 0;
}