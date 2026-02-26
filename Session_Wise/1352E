#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int *a = new int[n + 1];
        int *cnt = new int[n + 1];
        char *possible = new char[n + 1];

        for (int i = 0; i <= n; i++) {
            cnt[i] = 0;
            possible[i] = 0;
        }

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
        }

        for (int l = 1; l <= n; l++) {
            int sum = 0;
            for (int r = l; r <= n; r++) {
                sum += a[r];
                if (sum > n) break;
                if (r > l) possible[sum] = 1;
            }
        }

        int ans = 0;
        for (int x = 1; x <= n; x++) {
            if (possible[x]) ans += cnt[x];
        }

        cout << ans << "\n";

        delete[] a;
        delete[] cnt;
        delete[] possible;
    }
    return 0;
}
