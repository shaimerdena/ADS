#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int BFS(vector<vector<char>>& adj){
    int n = adj.size();
    int m = adj[0].size();

    int islands = 0;

    int cord_x[4] = {1, -1, 0, 0};
    int cord_y[4] = {0, 0, -1, 1};

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){

            if(adj[i][j] == '1'){
                islands++;

                queue<pair<int,int>> q;
                q.push({i, j});
                adj[i][j] = '0';

                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for(int k=0; k<4; k++){
                        int new_x = x + cord_x[k];
                        int new_y = y + cord_y[k];

                        if(new_x >= 0 && new_x < n && 
                            new_y >= 0 && new_y < m &&
                            adj[new_x][new_y] == '1'){
                                q.push({new_x, new_y});
                                adj[new_x][new_y] = '0';
                        }
                    }

                }
            }
            
        }
    }
    return islands;
}  


int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<char>> adj(n, vector<char> (m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char k;
            cin >> k;
            adj[i][j] = k;
        }
    }
    cout << BFS(adj) << endl;
    return 0;
}