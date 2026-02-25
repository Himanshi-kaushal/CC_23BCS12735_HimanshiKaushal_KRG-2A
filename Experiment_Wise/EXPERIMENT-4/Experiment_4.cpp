int Solution::cntBits(vector<int> &A) {
    const int MOD = 1000000007;
    long long ans = 0;
    int n = A.size();

    for (int bit = 0; bit < 32; bit++) {
        long long count1 = 0;

        for (int i = 0; i < n; i++) {
            if (A[i] & (1 << bit))
                count1++;
        }

        long long count0 = n - count1;

        // ordered pairs (i, j)
        ans = (ans + 2LL * count1 * count0) % MOD;
    }

    return (int)ans;
}
