#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int> > &adj, vector<int> &visited) {
    visited[node] = 1;
    for (int i = 0; i < (int)adj[node].size(); i++) {
        int next = adj[node][i];
        if (!visited[next]) {
            dfs(next, adj, visited);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int> > adj(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> visited(n + 1, 0);
    vector<int> reps; // representative of each component

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            reps.push_back(i);
            dfs(i, adj, visited);
        }
    }

    cout << reps.size() - 1 << "\n";
    for (int i = 0; i + 1 < (int)reps.size(); i++) {
        cout << reps[i] << " " << reps[i + 1] << "\n";
    }

    return 0;
}
