/** Гамильтонов цикл в полном графе **/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
 
using namespace std;
 
const string FILE_NAME = "fullham";
 
vector<vector<bool>> matrix;
 
void printGraph() {
    for (const auto &m : matrix) {
        for (const auto &v : m)
            cout << v << ' ';
        cout << '\n';
    }
}
 
int main() {
    freopen((FILE_NAME + ".in").c_str(), "r", stdin);
    freopen((FILE_NAME + ".out").c_str(), "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    size_t numVertices;
    cin >> numVertices;
 
    matrix.resize(numVertices, vector<bool>(numVertices, false));
    for (size_t i = 0; i < numVertices; ++i) {
        for (size_t q = 0; q < i; ++q) {
            char v;
            cin >> v;
            matrix[i][q] = v - '0';
            matrix[q][i] = v - '0';
        }
    }
    //printGraph();
 
    vector<size_t> result(numVertices);
    iota(result.begin(), result.end(), 0);
    while (true) {
        bool flag = true;
        for (size_t i = 0; i < numVertices - 1; ++i) {
            if (!matrix[result[i]][result[i + 1]]) {
                size_t save = i;
                bool flager = true;
                for (size_t q = i + 1; q < numVertices; ++q) {
                    if (matrix[result[i]][result[q]]) {
                        save = q;
                        flager = false;
                    }
                }
                if (flager) {
                    for (size_t q = 0; q < i; ++q) {
                        if (matrix[result[q]][result[i]]) {
                            swap(result[q], result[i]);
                            break;
                        }
                    }
                } else {
                    reverse(result.begin() + i + 1, result.begin() + save + 1);
                }
                flag = false;
            }
        }
 
        if (!matrix[result[numVertices - 1]][result[0]]) {
            for (size_t i = 0; i < numVertices; ++i) {
                if (matrix[result[numVertices - 1]][result[i]]) {
                    reverse(result.begin(), result.begin() + i + 1);
                    break;
                }
            }
            flag = false;
        }
 
        if (flag)
            break;
    }
 
    for (const auto &v : result)
        cout << v + 1 << ' ';
    return 0;
}