#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(int start, const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while(!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";
        for(int v = 0; v < n; v++) {
            if(adj[u][v] && !visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    int n = 5;
    vector<vector<int>> adj(n, vector<int>(n, 0));

    adj[0][1] = adj[1][0] = 1;
    adj[0][2] = adj[2][0] = 1;
    adj[1][3] = adj[3][1] = 1;
    adj[2][4] = adj[4][2] = 1;

    cout << "BFS starting from vertex 0: ";
    BFS(0, adj);
    return 0;
}
