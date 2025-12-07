#include <iostream>
#include <vector>
#include <queue>
using namespace std;

string BFS(vector<vector<int>> &adj, int start, int target){
    int n = adj.size();
    queue<int> q;
    vector<bool> visited(n, false);

    visited[start] = true;
    q.push(start);

    bool found = false;
    while(!q.empty()){
        int u = q.front();
        q.pop();

        if (u == target) return "YES";

        for(int v : adj[u]){
            if(visited[v] == false){
                q.push(v);
                visited[v] = true;
            }
        }
    }
    return "NO";
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);;
    for(int i=0; i<m; i++){
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }
    int start, target;
    cin >> start >> target;
    cout << BFS(adj, start, target);
    return 0;
}