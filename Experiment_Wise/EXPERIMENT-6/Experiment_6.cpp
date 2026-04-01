#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve() {
        int n;
        cin >> n;

        vector<string> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<vector<int>> g(26);
        vector<vector<int>> used(26, vector<int>(26, 0));
        vector<int> indeg(26, 0);

        for (int i = 0; i < n - 1; i++) {
            string s = a[i];
            string t = a[i + 1];

            int len = min((int)s.size(), (int)t.size());
            bool found = false;

            for (int j = 0; j < len; j++) {
                if (s[j] != t[j]) {
                    int u = s[j] - 'a';
                    int v = t[j] - 'a';

                    if (!used[u][v]) {
                        g[u].push_back(v);
                        used[u][v] = 1;
                        indeg[v]++;
                    }
                    found = true;
                    break;
                }
            }

            if (!found && s.size() > t.size()) {
                cout << "Impossible\n";
                return;
            }
        }

        queue<int> q;
        for (int i = 0; i < 26; i++) {
            if (indeg[i] == 0) q.push(i);
        }

        string ans = "";

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            ans += char(u + 'a');

            for (int v : g[u]) {
                indeg[v]--;
                if (indeg[v] == 0) q.push(v);
            }
        }

        if ((int)ans.size() != 26) {
            cout << "Impossible\n";
            return;
        }

        cout << ans << '\n';
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution s;
    s.solve();

    return 0;
}
