#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    long long *b = new long long[n];
    for (int i = 0; i < n; i++) cin >> b[i];

    long long *closed = new long long[n];
    for (int i = 0; i < n; i++) closed[i] = 0;

    long long sum = 0, cnt = 0, ans = 0;

    for (int i = n - 1; i >= 0; --i) {
        sum -= cnt;
        cnt -= closed[i];

        b[i] -= sum;
        if (b[i] <= 0) continue;

        int el = (i + 1 < k ? i + 1 : k);
        long long need = (b[i] + el - 1) / el;

        sum += need * el;
        cnt += need;
        ans += need;

        int stop = i - el;
        if (stop >= 0) closed[stop] += need;
    }

    cout << ans << "\n";
    return 0;
}
