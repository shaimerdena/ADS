//мин цена по матрице
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int v) {
     if (parent[v] == v)
           return v;
           parent[v] = find(parent[v]);
           return parent[v];
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if(a == b) return false;
        parent[b] = a;
        return true;
    }
};

int main() {
    int n;
    cin >> n;
    vector<tuple<long long,int,int>> edges;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            long long cost;
            cin >> cost;
            if(i<j){ 
                if(cost == 0) cost=0;  
                edges.push_back({cost, i+1, j+1});
            }
        }
    }
    sort(edges.begin(), edges.end());

    DSU dsu(n);
    long long total_cost = 0;

    for(auto &e : edges){
        long long cost;
        int u,v;
        tie(cost,u,v) = e;
        if(dsu.unite(u,v)) 
           total_cost += cost;
    }

    cout << total_cost;
}