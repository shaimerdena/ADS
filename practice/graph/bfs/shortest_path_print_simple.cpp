#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> bfs(int start, int target, const vector<vector<int>> &adj){
    int n = adj.size();
    vector<int> used(n, 0);
    vector<int> parent(n, -1);
    queue<pair<int,int>> q;

    q.push({start, 0});
    used[start] = 1;

    while(!q.empty()){
        int u = q.front().first;
        int d = q.front().second;
        q.pop();
        
        if(u == target) break;

        for(int i=0; i<adj[u].size(); i++){
            int y = adj[u][i];
            if(used[y] == 0){
                used[y] = 1;
                parent[y] = u;
                q.push({y, d+1});
            }
        }
    }
    if(!used[target]) return {};

    vector<int> path;
    for(int v = target; v!=-1; v = parent[v]){
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    return path;
}

int main(){
    vector<vector<int>> adj(8);
    adj[0] = {1, 2, 4, 5};
    adj[1] = {0};
    adj[2] = {0, 3};
    adj[3] = {2, 4};
    adj[4] = {0, 3, 7};
    adj[5] = {0};
    adj[6] = {7};
    adj[7] = {4, 6};

    vector<int> path = bfs(0, 6, adj);
    for(int i=0; i<path.size(); i++){
        cout << path[i] << " ";
    }

    return 0;
}