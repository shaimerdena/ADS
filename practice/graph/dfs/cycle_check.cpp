#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int start, const vector<vector<int>> &adj) {
    int n = adj.size();

    vector<int> used(n, 0);     // 0 — не был, 1 — в стеке, 2 — вышел
    vector<int> parent(n, -1);  // чтобы не ловить обратное ребро к родителю

    stack<int> st;      // стек DFS
    stack<int> path;    // реальный путь

    st.push(start);
    path.push(start);
    used[start] = 1;

    while (!st.empty()) {

        int u = st.top();
        bool pushed = false;

        for (int y : adj[u]) {

            if (y == parent[u]) continue;  // не считаем возврат к родителю циклом

            if (used[y] == 0) {
                parent[y] = u;
                st.push(y);
                path.push(y);
                used[y] = 1;
                pushed = true;
                break;
            }

            // цикл найден
            if (used[y] == 1) {
                cout << "Cycle: ";

                // собираем цикл из path
                stack<int> tmp = path;
                vector<int> cyc;
                while (!tmp.empty()) {
                    cyc.push_back(tmp.top());
                    if (tmp.top() == y) break;
                    tmp.pop();
                }

                // цикл от y до u
                for (int i = cyc.size() - 1; i >= 0; i--)
                    cout << cyc[i] << " ";

                cout << endl;
            }
        }

        if (!pushed) {
            st.pop();
            used[u] = 2;
            path.pop();
        }
    }
}

int main() {
    vector<vector<int>> adj(8);
    adj[0] = {1, 2, 4, 5};
    adj[1] = {0};
    adj[2] = {0, 3};
    adj[3] = {2, 4};
    adj[4] = {0, 3, 7};
    adj[5] = {0, 6};
    adj[6] = {5, 7};
    adj[7] = {4, 6};

    dfs(0, adj);
    return 0;
}
