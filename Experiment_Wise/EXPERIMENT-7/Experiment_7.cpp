class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        const int INF = 1e9;
        vector<int> dist(n, INF);
        dist[src] = 0;

        for (int i = 0; i <= k; i++) {
            vector<int> temp = dist;

            for (int j = 0; j < flights.size(); j++) {
                int u = flights[j][0];
                int v = flights[j][1];
                int cost = flights[j][2];

                if (dist[u] != INF && dist[u] + cost < temp[v]) {
                    temp[v] = dist[u] + cost;
                }
            }

            dist = temp;
        }

        return dist[dst] == INF ? -1 : dist[dst];
    }
};
