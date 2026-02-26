#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long S;
    cin >> n >> S;

    long long *a = new long long[n + 1];
    for (int i = 1; i <= n; i++) cin >> a[i];

    long long *cost = new long long[n];

    auto feasible = [&](int k, long long &sumOut) -> bool {
        for (int i = 1; i <= n; i++) cost[i - 1] = a[i] + 1LL * i * k;
        nth_element(cost, cost + k, cost + n);
        long long s = 0;
        for (int i = 0; i < k; i++) s += cost[i];
        sumOut = s;
        return s <= S;
    };

    int lo = 0, hi = n;
    long long bestSum = 0;

    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        long long s;
        if (feasible(mid, s)) {
            lo = mid;
            bestSum = s;
        } else {
            hi = mid - 1;
        }
    }

    long long finalSum = 0;
    if (lo > 0) feasible(lo, finalSum);

    cout << lo << " " << finalSum << "\n";

    delete[] a;
    delete[] cost;
    return 0;
}
