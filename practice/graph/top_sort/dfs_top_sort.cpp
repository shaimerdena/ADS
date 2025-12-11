#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int v, const vector<vector<int>> &adj, vector<int> &visited, stack<int> &order){
    visited[v] = 1;
    
    // Visit all neighbors first
    for(int i=0; i<adj[v].size(); i++){
        int y = adj[v][i];
        if(!visited[y]){
            dfs(y, adj, visited, order);
        }
    }

    // Add current vertex to stack after visiting all descendants
    order.push(v);
}   

void top_sort(const vector<vector<int>> &adj){
    int n = adj.size();
    vector<int> visited(n, 0);
    stack<int> order;

    // Process all vertices
    for(int i=0; i<n; i++){
        if(!visited[i]){
            dfs(i, adj, visited, order);
        }
    }

    cout << "Top_sort:" << endl;
    while(!order.empty()){
        cout << order.top() << " ";
        order.pop();
    }
}

int main(){
    //DAG example
    vector<vector<int>> adj(4);
    adj[0] = {1, 2};
    adj[1] = {3};
    adj[2] = {3};
    top_sort(adj);
    return 0;
}