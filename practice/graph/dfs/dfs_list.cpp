#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool dfs(int start, int target, const vector<vector<int>> &adj){
    int n = adj.size();
    vector<int> used(n, 0);
    stack<int> s;

    s.push(start);
    used[start] = 1;

    while(!s.empty()){
        int k = s.top();
        if(k == target){
            return true;
        }
        s.pop();
        for(int i=0; i<adj[k].size(); i++){
            int y = adj[k][i];
            if(used[y] == 0){
                used[y] = 1;
                s.push(y);
            }
        }
    }
    return false;
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

    cout << dfs(3, 1, adj) << endl;
    return 0;
}