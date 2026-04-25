#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Edge {
    int u, v, wt;
};

bool cmp(Edge a, Edge b) {
    return a.wt < b.wt;
}

int parent[100];
int rankArr[100];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]); 
    return parent[x];
}

void unionSet(int a, int b) {
    int pa = find(a);
    int pb = find(b);

    if (pa == pb) return;

    if (rankArr[pa] < rankArr[pb])
        parent[pa] = pb;
    else if (rankArr[pa] > rankArr[pb])
        parent[pb] = pa;
    else {
        parent[pb] = pa;
        rankArr[pa]++;
    }
}

int minCostConnectPoints(int points[][2], int n) {
    vector<Edge> edges;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int dist = abs(points[i][0] - points[j][0]) +
                       abs(points[i][1] - points[j][1]);

            edges.push_back({i, j, dist});
        }
    }

    sort(edges.begin(), edges.end(), cmp);

    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rankArr[i] = 0;
    }

    int cost = 0, count = 0;

    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        if (find(u) != find(v)) {
            unionSet(u, v);
            cost += edges[i].wt;
            count++;

            if (count == n - 1)
                break;
        }
    }

    return cost;
}

int main() {
    int points[5][2] = {{0,0},{2,2},{3,10},{5,2},{7,0}};
    cout << minCostConnectPoints(points, 5);
    return 0;
}
