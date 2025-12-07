#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> x(n), y(n);
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];

    const long long INF = 4e18;
    vector<long long> dist(n, INF);
    dist[0] = 0;  

    priority_queue<pair<long long,int>,
                   vector<pair<long long,int>>,
                   greater<pair<long long,int>>> pq;

    pq.push({0, 0});

    while (!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();

        if (d != dist[v]) continue;

        for (int u = 0; u < n; u++) {
            long long w = llabs(x[v] - x[u]) + llabs(y[v] - y[u]);
            long long nd = max(dist[v], w);

            if (nd < dist[u]) {
                dist[u] = nd;
                pq.push({nd, u});
            }
        }
    }

    cout << dist[n-1];
}