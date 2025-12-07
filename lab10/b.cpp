#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int the_shortest_path(int start, int end, const vector<vector<int>> &adj) {
    int n = adj.size();
    vector<int> visited(n, -1);     
    queue<int> q;

    visited[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int v = q.front(); q.pop();
        if (v == end) return visited[v];

        for (int u = 0; u < n; ++u) {
            if (adj[v][u] && visited[u] == -1) {
                visited[u] = visited[v] + 1;
                q.push(u);
            }
        }
    }
    return -1; 
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> adj(n, vector<int> (n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> adj[i][j];
        }
    }
    int start, end;
    cin >> start >> end;
    start--; end--;
    cout << the_shortest_path(start, end, adj) << endl;
    return 0;
}