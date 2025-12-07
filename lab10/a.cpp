#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int BFS(vector<vector<int>>& adj) {
    int n = adj.size();
    int m = adj[0].size();

    int mushes = 0, time = 0;
    queue<pair<pair<int, int>, int>> q;
    for(int i=0; i<adj.size(); i++){
        for(int j=0; j<adj[0].size(); j++){
            if(adj[i][j] == 1){
                mushes++;
            }
            if(adj[i][j] == 2){
                q.push({{i, j}, 0});
            }
        }
    }

    if(mushes == 0) return 0;

    int directions_of_x[4] = {-1, 1, 0, 0};
    int directions_of_y[4] = {0, 0, -1, 1};

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int t = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int mushroom_x = x + directions_of_x[i];
            int mushroom_y = y + directions_of_y[i];
            if(mushroom_x >= 0 && mushroom_x < n && mushroom_y >= 0 && mushroom_y < m){
                if(adj[mushroom_x][mushroom_y] == 1){
                    adj[mushroom_x][mushroom_y] = 2;
                    mushes--;
                    q.push({{mushroom_x, mushroom_y}, t + 1});
                    time = t + 1;
                }
            }
        }
    }
    if(mushes == 0) return time;
    else return -1;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n, vector<int> (m));
    int start;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int x;
            cin >> x;
            adj[i][j] = x;
        }
    }
    cout << BFS(adj) << endl;
    return 0;
}