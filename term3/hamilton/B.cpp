/** Поиск гамильтонова цикла в условиях теоремы Хватала **/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
 
const string FILE_NAME = "chvatal";
 
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
    vector<size_t> order;
    for (size_t i = 0; i < numVertices; ++i) {
        for (size_t q = 0; q < i; ++q) {
            char v;
            cin >> v;
            matrix[i][q] = matrix[q][i] = v == '1';
        }
        order.push_back(i);
    }
 
    //printGraph();
 
    size_t t = 0;
    for (size_t i = 0; i < numVertices * numVertices - numVertices; ++i) {
        size_t first = order[t], second = order[t + 1];
        if (!matrix[first][second]) {
            int index = -1;
            for (size_t q = 2; q < numVertices - 1; ++q) {
                if (matrix[first][order[t + q]]) {
                    if (matrix[second][order[t + q + 1]]) {
                        index = q;
                        break;
                    }
                }
            }
            if (index == -1) {
                for (size_t q = 2; q < numVertices; ++q) {
                    if (matrix[first][order[t + q]]) {
                        index = q;
                        break;
                    }
                }
            }
            reverse(order.begin() + t + 1, order.begin() + t + index + 1);
        }
        order.push_back(order[t++]);
    }
 
    /*if (order.size() > 1)
        for (size_t t = 0; t < order.size(); ++t)
            if (!matrix[order[t]][order[(t + 1) % order.size()]])
                return -100;*/
 
    for (size_t i = t; i < order.size(); ++i)
        cout << order[i] + 1 << ' ';
    return 0;
}