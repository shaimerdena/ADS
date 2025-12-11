#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

int main() {
    int n = 4;
    vector<vector<int>> dist(n, vector<int>(n, INF));

    // расстояние до себя = 0
    for(int i=0;i<n;i++) dist[i][i] = 0;

    // добавим рёбра
    dist[0][1] = 4;
    dist[0][2] = 1;
    dist[2][1] = 2;
    dist[1][3] = 1;
    dist[2][3] = 5;

    // Флойда
    for(int k=0;k<n;k++) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // вывод
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}
