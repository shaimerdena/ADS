#include <iostream>
#include <vector>
using namespace std;

bool bipartite_dfs(int v, int c, const vector<vector<int>> &vec, vector<int> &color){
    color[v] = c; // ставим цвет

    for(int y : vec[v]){
        if(color[y] == 0){  
            if(!bipartite_dfs(y, 3 - c, vec, color))
                return false;
        }
        else if(color[y] == c){
            return false;
        }
    }

    return true;
}

int main() {
    int n = 6;
    vector<vector<int>> adj(n);
    vector<int> used(n, 0);

    // Пример графа
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 4, 5};
    adj[3] = {1};
    adj[4] = {2};
    adj[5] = {2};

    bool ok = true;
    for(int i = 0; i < n; i++){
        if(used[i] == 0){          
            if(!bipartite_dfs(i, 1, adj, used)){
                ok = false;
                break;
            }
        }
    }

    if(ok == true) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}