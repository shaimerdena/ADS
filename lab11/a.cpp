// сумма мин для перекрывания 
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n, m;
    cin>>n>>m;

    vector<vector<pair<int,int>>> st(n + 1);

    for(int i = 0; i < m; i++){
        int l, r, c;
        cin >> l >> r >> c;
        st[l].push_back({r, c});
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    long long ans = 0;

    for(int i = 1; i < n; i++){
        for (auto seg : st[i]){ 
            int r = seg.first;
            int c = seg.second;
            pq.push({c, r});
        }

        while(!pq.empty() && pq.top().second <= i){
            pq.pop();
        }

        ans += pq.top().first;
    }

    cout << ans;
    return 0;
}