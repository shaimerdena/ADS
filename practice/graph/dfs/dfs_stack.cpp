#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int v, const vector<vector<int>> &adj){
    int n = adj.size();
    vector<int> visited(n, 0);
    stack<int> s;

    s.push(v);
    while(!s.empty()){
        int u = s.top();
        cout << u << " ";
        s.pop();
        for(int i=0; i<adj[u].size(); i++){
            int y = adj[u][i];
            if(visited[y] == 0){
                s.push(y);
                visited[y] = 1;
            }
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

    dfs(0, adj);
    return 0;
}