#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;
    vector<int> vis(n + 1, 0);
    int ans = 0;
    pq.push({0, 1});  
    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int wt = it.first;
        int node = it.second;
        if (vis[node] == 1) continue;
        vis[node] = 1;
        ans += wt;
        for (auto it : graph[node]) {
            int adjNode = it.first;
            int edgeWt = it.second;
            if (vis[adjNode] == 0) {
                pq.push({edgeWt, adjNode});
            }
        }
    }
    cout << "Minimum weight of Spanning Tree = " << ans << endl;
    return 0;
}
