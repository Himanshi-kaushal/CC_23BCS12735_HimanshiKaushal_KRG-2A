#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve() {
        int n, m;
        cin >> n >> m;

        vector<vector<pair<int, int>>> g(n + 1);

        for (int i = 0; i < m; i++) {
            int a, b, w;
            cin >> a >> b >> w;
            g[a].push_back({b, w});
            g[b].push_back({a, w});
        }

        const long long INF = 1e18;
        vector<long long> dist(n + 1, INF);
        vector<int> parent(n + 1);

        for (int i = 1; i <= n; i++) parent[i] = i;

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        dist[1] = 0;
        pq.push({0, 1});

        while (!pq.empty()) {
            long long d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (d > dist[u]) continue;

            for (auto it : g[u]) {
                int v = it.first;
                int w = it.second;

                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    parent[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }

        if (dist[n] == INF) {
            cout << -1 << '\n';
            return;
        }

        vector<int> path;
        int cur = n;

        while (parent[cur] != cur) {
            path.push_back(cur);
            cur = parent[cur];
        }
        path.push_back(1);

        reverse(path.begin(), path.end());

        for (int x : path) cout << x << " ";
        cout << '\n';
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution s;
    s.solve();

    return 0;
}
