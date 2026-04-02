#include <iostream>
using namespace std;
const int N = 100005;
const int M = 100005;
int parent[N];
int Size[N];
struct Edge {
    int u, v, wt;
};
Edge edges[M];
void make(int node) {
    parent[node] = node;
    Size[node] = 1;
}
int find(int node) {
    if (parent[node] == node)
        return node;
    return parent[node] = find(parent[node]);
}
void Union(int a, int b) {
    int p1 = find(a);
    int p2 = find(b);
    if (p1 != p2) {
        if (Size[p1] < Size[p2]) {
            swap(p1, p2);
        }
        parent[p2] = p1;
        Size[p1] += Size[p2];
    }
}
void sortEdges(int m) {
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < m - i - 1; j++) {
            if (edges[j].wt > edges[j + 1].wt) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        make(i);
    }
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].wt;
    }
    sortEdges(m);
    int totalCost = 0;
    cout << "Edges in MST are:\n";
    for (int i = 0; i < m; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int wt = edges[i].wt;
        if (find(u) != find(v)) {
            Union(u, v);
            totalCost += wt;
            cout << u << " " << v << " " << wt << endl;
        }
    }
    cout << "Minimum Cost = " << totalCost << endl;
    return 0;
}
