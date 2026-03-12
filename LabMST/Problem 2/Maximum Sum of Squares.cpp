class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long MOD = 1000000007;
        vector<int> cnt(32, 0);

        for (int i = 0; i < nums.size(); i++) {
            for (int bit = 0; bit < 32; bit++) {
                if (nums[i] & (1 << bit)) {
                    cnt[bit]++;
                }
            }
        }

        long long ans = 0;

        for (int i = 0; i < k; i++) {
            long long val = 0;

            for (int bit = 0; bit < 32; bit++) {
                if (cnt[bit] > 0) {
                    val |= (1LL << bit);
                    cnt[bit]--;
                }
            }

            ans = (ans + (val * val) % MOD) % MOD;
        }

        return (int)ans;
    }
};
