#include <iostream> 
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> g;

vector<pair<int,int>> cycleEdges;
vector<int> st;
vector<int> color;

bool dfs_find_cycle(int u){
    color[u] = 1;
    st.push_back(u);
    for(int v : g[u]){
        if(color[v] == 0){
            if(dfs_find_cycle(v)) return true;
        } else if(color[v] == 1){
            int idx = (int)st.size() - 1;
            while(idx >= 0 && st[idx] != v) idx--;
            if(idx < 0) continue;
            for(int i = idx; i + 1 < (int)st.size(); ++i){
                cycleEdges.emplace_back(st[i], st[i+1]);
            }
            cycleEdges.emplace_back(st.back(), v);
            return true;
        }
    }
    st.pop_back();
    color[u] = 2;
    return false;
}

bool check_remove_edge_makes_dag(const pair<int,int> &rem, const vector<int> &indeg_orig){
    vector<int> indeg = indeg_orig;
    int ru = rem.first, rv = rem.second;

    indeg[rv]--;
    queue<int> q;
    for(int i = 1; i <= n; ++i) if(indeg[i] == 0) q.push(i);
    int cnt = 0;
    while(!q.empty()){
        int u = q.front(); q.pop();
        ++cnt;
        for(int to : g[u]){
            if(u == ru && to == rv) continue;
            --indeg[to];
            if(indeg[to] == 0) q.push(to);
        }
    }
    return cnt == n;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if(!(cin >> n >> m)) return 0;
    g.assign(n+1, {});
    vector<int> indeg(n+1, 0);
    for(int i = 0; i < m; ++i){
        int x, y; cin >> x >> y;
        g[x].push_back(y);
        indeg[y]++;
    }

    color.assign(n+1, 0);
    for(int i = 1; i <= n; ++i){
        if(color[i] == 0){
            if(dfs_find_cycle(i)) break;
        }
    }

    if(cycleEdges.empty()){
        cout << "YES\n";
        return 0;
    }

    for(auto &e : cycleEdges){
        if(check_remove_edge_makes_dag(e, indeg)){
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}