#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int bfs(int start, int target, const vector<vector<int>> &adj){
    int n = adj.size();
    vector<int> used(n, 0);
    queue<pair<int, int>> q;
    q.push({start, 0});

    while(!q.empty()){
        int u = q.front().first;
        int d = q.front().second;

        if(u == target) return d;

        used[u] = 1;
        q.pop();
        
        for(int i=0; i<adj[u].size(); i++){
            int y = adj[u][i];
            if(used[y] == 0){
                used[y] = 1;
                q.push({y, d+1});
            }
        }
    }
    return -1;
}

int main(){
    vector<vector<int>> adj(8);
    adj[0] = {1, 2, 4, 5};
    adj[1] = {0};
    adj[2] = {0, 3};
    adj[3] = {2, 4};
    adj[4] = {0, 3, 7};
    adj[5] = {0, 6};
    adj[6] = {5, 7};
    adj[7] = {4, 6};

    cout << bfs(0, 6, adj) << endl;
    return 0;
}