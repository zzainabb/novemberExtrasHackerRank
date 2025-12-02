#include <iostream>
#include <string>
#include <vector>
using namespace std;

long journeyToMoon(int n, vector<vector<int>> astronaut) {
    vector<vector<int>> adj(n);

    for (auto& p : astronaut) {
        int u = p[0], v = p[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n, false);
    vector<long> sizes;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            long count = 0;
            stack<int> st;
            st.push(i);
            visited[i] = true;

            while (!st.empty()) {
                int node = st.top(); st.pop();
                count++;

                for (int nei : adj[node]) {
                    if (!visited[nei]) {
                        visited[nei] = true;
                        st.push(nei);
                    }
                }
            }

            sizes.push_back(count);
        }
    }

    long result = 0;
    long sum = 0;

    for (long sz : sizes) {
        result += sum * sz;
        sum += sz;
    }

    return result;
}
