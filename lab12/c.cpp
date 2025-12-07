#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int bfs(int n, vector<vector<int>> &g){
    vector<int> d(n, -1);
    queue<int> q;
    d[0]=0; q.push(0);
    while(!q.empty()){
        int u=q.front(); q.pop();
        for(int v:g[u]){
            if(d[v]==-1){
                d[v]=d[u]+1;
                q.push(v);
            }
        }
    }
    return d[n-1];
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> airline(n);
    vector<vector<bool>> hasAir(n, vector<bool>(n,0));
    
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v; u--;v--;
        airline[u].push_back(v);
        airline[v].push_back(u);
        hasAir[u][v]=hasAir[v][u]=1;
    }
    vector<vector<int>> road(n);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j && !hasAir[i][j]) road[i].push_back(j);
        }
    }
    int d1=bfs(n, airline);
    int d2=bfs(n, road);
    if(d1==-1 || d2==-1) cout<<-1;
    else cout<<max(d1,d2);
}