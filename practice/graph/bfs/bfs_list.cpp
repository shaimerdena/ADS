#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int start, vector<vector<int>> &adj){
    int n = adj.size();
    queue<int> q;
    vector<bool> visited(n, false);

    visited[start] = true;
    q.push(start);

    while(!q.empty()){
        int u = q.front();
        q.pop();
        cout << u << " ";
        for(int v : adj[u]){
            if(visited[v] == false){
                q.push(v);
                visited[v] = true;
            }
        }
    }
}

int main() {
    int n = 6;
    vector<vector<int>> adj(n);

    // Пример графа
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 4, 5};
    adj[3] = {1};
    adj[4] = {2};
    adj[5] = {2};

    bfs(0, adj);
}