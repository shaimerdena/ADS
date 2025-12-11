#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs_stack(int start, const vector<vector<int>> &adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    stack<int> st;
    st.push(start);

    while (!st.empty()) {
        int v = st.top();
        st.pop();

        if (!visited[v]) {
            cout << v << " ";
            visited[v] = true;
        }

        for (int u = n - 1; u >= 0; u--) {
            if (adj[v][u] && !visited[u]) {
                st.push(u);
            }
        }
    }
}

int main() {
    int n = 5;
    vector<vector<int>> adj(n, vector<int>(n, 0));

    adj[0][1] = 1; adj[1][0] = 1;
    adj[0][2] = 1; adj[2][0] = 1;
    adj[1][3] = 1; adj[3][1] = 1;
    adj[2][4] = 1; adj[4][2] = 1;

    cout << "DFS starting from node 0: ";
    dfs_stack(0, adj);
    cout << endl;

    return 0;
}
