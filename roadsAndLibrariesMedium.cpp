#include <vector>
#include <queue>
using namespace std;

long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
    if (c_lib <= c_road) {
        return (long)n * c_lib;
    }

    vector<vector<int>> adj(n + 1);
    for (auto& e : cities) {
        int u = e[0], v = e[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n + 1, false);
    long total_cost = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            long component_size = 0;
            queue<int> q;
            q.push(i);
            visited[i] = true;

            while (!q.empty()) {
                int node = q.front();
                q.pop();
                component_size++;

                for (int nei : adj[node]) {
                    if (!visited[nei]) {
                        visited[nei] = true;
                        q.push(nei);
                    }
                }
            }

            total_cost += c_lib + (component_size - 1) * c_road;
        }
    }

    return total_cost;
}
