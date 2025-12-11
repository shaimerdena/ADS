#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int start, const vector<vector<int>> &adj){
    int n = adj.size();
    vector<int> used(n, 0);
    queue<pair<int,int>> q;
    q.push({start, 0});

    while(!q.empty()){
        int u = q.front().first;
        int d = q.front().second;

        cout << u << ": " << d << endl;
        q.pop();
        for(int i=0; i<adj[u].size(); i++){
            int y = adj[u][i];
            if(used[y] == 0){
                used[y] = 1;
                q.push({y, d+1});
            }
        }  
    }
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

    bfs(0, adj);
    return 0;
}