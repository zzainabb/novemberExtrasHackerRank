#include <vector>
#include <queue>
using namespace std;

vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    vector<vector<int>> adj(n + 1);

    for (auto& e : edges) {
        int u = e[0], v = e[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist(n + 1, -1);
    queue<int> q;

    dist[s] = 0;
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 6;
                q.push(v);
            }
        }
    }

    vector<int> result;
    for (int i = 1; i <= n; i++) {
        if (i == s) continue;
        result.push_back(dist[i]);
    }

    return result;
}
