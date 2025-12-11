#include <iostream>
#include <vector>
using namespace std;

vector<int> topSortKahn(const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> indeg(n, 0);

    // 1. считаем входящие рёбра
    for (int u = 0; u < n; u++) {
        for (int v : adj[u])
            indeg[v]++;
    }
    queue<int> q;
    // 2. все вершины с indeg = 0 в очередь
    for (int i = 0; i < n; i++) {
        if (indeg[i] == 0)
            q.push(i);
    }
    vector<int> order;
    // 3. обработка
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);

        for (int v : adj[u]) {
            indeg[v]--;
            if (indeg[v] == 0)
                q.push(v);
        }
    }
    // 4. проверка на цикл
    if (order.size() != n) {
        // цикл существует
        return {}; 
    }
    return order;
}

int main(){
    //DAG example
    vector<vector<int>> adj(4);
    adj[0] = {1, 2};
    adj[1] = {3};
    adj[2] = {3};
    topSortKahn(adj);
    return 0;
}