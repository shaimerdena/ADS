#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int u, v, w;
};

void bellman(int n, int start, vector<Edge>& edges) {
    vector<int> dist(n, 1e9);
    dist[start] = 0;

    // V-1 итераций релаксации
    for(int i = 0; i < n-1; i++) {
        for(auto &e : edges) {
            if(dist[e.u] < 1e9 && dist[e.v] > dist[e.u] + e.w) {
                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }

    // Проверка на отрицательный цикл
    for(auto &e : edges) {
        if(dist[e.u] < 1e9 && dist[e.v] > dist[e.u] + e.w) {
            cout << "Negative cycle detected\n";
            return;
        }
    }

    for(int i=0;i<n;i++) {
        cout << "dist["<<i<<"] = " << dist[i] << "\n";
    }
}

int main() {
    int n = 5;
    vector<Edge> edges;

    edges.push_back({0,1,4});
    edges.push_back({0,2,1});
    edges.push_back({2,1,2});
    edges.push_back({1,3,1});
    edges.push_back({2,3,5});
    edges.push_back({3,4,3});

    bellman(n, 0, edges);
}
