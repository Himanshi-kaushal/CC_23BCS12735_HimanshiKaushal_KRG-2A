#include <iostream>
using namespace std;
const int N = 100000;
int parent[N];
int Size[N];
void make(int node) {
    parent[node] = node;
    Size[node] = 1;
}
int find(int node) {
    if (parent[node] == node)
        return node;

    return parent[node] = find(parent[node]);
}
void Union(int node1, int node2) {
    int p1 = find(node1);
    int p2 = find(node2);
    if (p1 != p2) {
        if (Size[p1] < Size[p2]) {
            swap(p1, p2);
        }
        parent[p2] = p1;
        Size[p1] += Size[p2];
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        make(i);
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        if (find(u) != find(v)) {
            Union(u, v);
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (find(i) == i) {
            cnt++;
        }
    }
    cout << "Total no of Components= " << cnt << endl;
    return 0;
}
