#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long k;
    string s;
    cin >> k >> s;
    int n = (int)s.size();

    if (k == 0) {
        long long ans = 0;
        long long run = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') run++;
            else {
                ans += run * (run + 1) / 2;
                run = 0;
            }
        }
        ans += run * (run + 1) / 2;
        cout << ans << "\n";
        return 0;
    }

    int *pos = new int[n + 3];
    int m = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') pos[++m] = i + 1;
    }

    if (m < k) {
        cout << 0 << "\n";
        delete[] pos;
        return 0;
    }

    pos[0] = 0;
    pos[m + 1] = n + 1;

    long long ans = 0;
    for (int i = 1; i + (int)k - 1 <= m; i++) {
        int left = pos[i] - pos[i - 1];
        int right = pos[i + (int)k] - pos[i + (int)k - 1];
        ans += 1LL * left * right;
    }

    cout << ans << "\n";
    delete[] pos;
    return 0;
}
