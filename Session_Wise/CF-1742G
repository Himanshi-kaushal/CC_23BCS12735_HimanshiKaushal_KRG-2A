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
        long long *a = new long long[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        char *used = new char[n];
        for (int i = 0; i < n; i++) used[i] = 0;

        long long cur = 0;
        long long all = 0;
        for (int i = 0; i < n; i++) all |= a[i];

        long long *ans = new long long[n];
        int m = 0;

        for (int step = 0; step < 31 && cur != all; step++) {
            int bestIdx = -1;
            long long bestVal = cur;
            for (int i = 0; i < n; i++) {
                if (used[i]) continue;
                long long v = cur | a[i];
                if (v > bestVal) {
                    bestVal = v;
                    bestIdx = i;
                }
            }
            if (bestIdx == -1) break;
            used[bestIdx] = 1;
            ans[m++] = a[bestIdx];
            cur = bestVal;
        }

        for (int i = 0; i < n; i++) {
            if (!used[i]) ans[m++] = a[i];
        }

        for (int i = 0; i < n; i++) {
            cout << ans[i] << (i + 1 == n ? '\n' : ' ');
        }

        delete[] a;
        delete[] used;
        delete[] ans;
    }
    return 0;
}
