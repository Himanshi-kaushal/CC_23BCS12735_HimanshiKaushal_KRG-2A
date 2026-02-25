#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n + 1), b(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> b[i];

        // Prefix sum of b
        vector<long long> pref(n + 1, 0);
        for (int i = 1; i <= n; i++)
            pref[i] = pref[i - 1] + b[i];

        vector<long long> cnt(n + 2, 0), extra(n + 2, 0);

        for (int i = 1; i <= n; i++) {
            long long need = a[i] + pref[i - 1];

            // Binary search for last taster
            int r = upper_bound(pref.begin(), pref.end(), need) - pref.begin() - 1;

            if (r >= i) {
                cnt[i] += 1;
                cnt[r + 1] -= 1;
                extra[r + 1] += need - pref[r];
            } else {
                extra[i] += a[i];
            }
        }

        // Prefix sum on cnt
        for (int i = 1; i <= n; i++)
            cnt[i] += cnt[i - 1];

        // Output result
        for (int i = 1; i <= n; i++) {
            cout << cnt[i] * b[i] + extra[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
