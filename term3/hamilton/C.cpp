/** Интерактивная восточная сказка */
#include <iostream>
#include <string>
#include <vector>
#include <list>
 
using namespace std;
 
const string FILE_NAME = "guyaury";
 
vector<vector<bool>> matrix;
 
void printGraph() {
    for (const auto &m : matrix) {
        for (const auto &v : m)
            cout << v << ' ';
        cout << '\n';
    }
}
 
int main() {
    /*freopen((FILE_NAME + ".in").c_str(), "r", stdin);
    freopen((FILE_NAME + ".out").c_str(), "w", stdout);*/
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    size_t numQuery;
    cin >> numQuery;
 
    list<size_t> order;
    order.push_back(0);
    for (size_t i = 1; i < numQuery; ++i) {
        int left = -1, right = (int) i;
        while (right > left + 1) {
 
            int middle = left + ((right - left) >> 1);
            auto midOrderIterator = order.begin();
            advance(midOrderIterator, middle);
 
            cout << "1 " << *midOrderIterator + 1 << " " << i + 1 << endl;
 
            string ans;
            cin >> ans;
 
            if (ans == "YES")
                left = middle;
            else
                right = middle;
        }
        auto insertPosition = order.begin();
        advance(insertPosition, right);
        order.insert(insertPosition, i);
    }
 
    cout << "0 ";
    for (const auto &u : order)
        cout << u + 1 << " ";
    return 0;
}