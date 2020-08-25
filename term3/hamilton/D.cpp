/** Цикл в турнире */
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
const string FILE_NAME = "guyaury";
 
vector<vector<size_t>> graph;
vector<bool> used;
vector<size_t> order;
 
void topSort(int v) {
    used[v] = true;
    for (auto to : graph[v]) {
        if (!used[to]) {
            topSort(to);
        }
    }
    order.push_back(v);
}
 
int main() {
    freopen((FILE_NAME + ".in").c_str(), "r", stdin);
    freopen((FILE_NAME + ".out").c_str(), "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    size_t numVertices;
    cin >> numVertices;
 
    graph.resize(numVertices);
    for (size_t v = 0; v < numVertices; ++v) {
        for (size_t to = 0; to < v; ++to) {
            char i;
            cin >> i;
            if (i == '1')
                graph[v].push_back(to);
            if (i == '0')
                graph[to].push_back(v);
        }
    }
    for (size_t i = 0; i < numVertices; ++i) {
        used.assign(numVertices, false);
        topSort(i);
        reverse(order.begin(), order.end());
        if (find(graph[order[numVertices - 1]].begin(), graph[order[numVertices - 1]].end(), order[0]) != graph[order[numVertices - 1]].end()) {
            for (const auto &v : order)
                cout << v + 1 << ' ';
            break;
        }
        order.clear();
    }
    return 0;
}