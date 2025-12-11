#include <iostream>
#include <vector>
using namespace std;

void dfs(int v, const vector<vector<int>> &adj, vector<int> &visited){    
    visited[v] = 1;
    cout << v << " ";

    for(int i=0; i<adj[v].size(); i++){
        int y = adj[v][i];
        if(!visited[y]){
            dfs(y, adj, visited);
        }
    }
}

int main() {
    vector<vector<int>> adj(8);
    adj[0] = {1, 2, 4, 5};
    adj[1] = {0};
    adj[2] = {0, 3};
    adj[3] = {2, 4};
    adj[4] = {0, 3, 7};
    adj[5] = {0, 6};
    adj[6] = {5, 7};
    adj[7] = {4, 6};
    vector<int> visited(adj.size(), 0);

    dfs(0, adj, visited);
    return 0;
}