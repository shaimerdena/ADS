#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> PII; // (distance, vertex)

void dijkstra(int start, const vector<vector<PII>>& adj) {
    int n = adj.size();
    vector<int> dist(n, 1e9);
    dist[start] = 0;

    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push({0, start});

    while(!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();

        if(d != dist[v]) continue;   // устаревшая запись

        for(auto [to, w] : adj[v]) {
            if(dist[to] > dist[v] + w) {
                dist[to] = dist[v] + w;
                pq.push({dist[to], to});
            }
        }
    }

    for(int i=0;i<n;i++) {
        cout << "dist[" << i << "] = " << dist[i] << "\n";
    }
}

int main() {
    int n = 5;
    vector<vector<PII>> adj(n);

    // пример: граф
    adj[0].push_back({1, 4});
    adj[0].push_back({2, 1});
    adj[2].push_back({1, 2});
    adj[1].push_back({3, 1});
    adj[2].push_back({3, 5});
    adj[3].push_back({4, 3});

    dijkstra(0, adj);
}
