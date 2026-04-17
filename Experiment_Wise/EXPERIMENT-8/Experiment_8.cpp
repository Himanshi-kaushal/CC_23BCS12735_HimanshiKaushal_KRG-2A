class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        int dp[501] = {0};
        
        for (int i = 0; i < n; i++) {
            int maxi = 0;
            
            for (int j = i; j >= 0 && j > i - k; j--) {
                if (arr[j] > maxi)
                    maxi = arr[j];
                
                int len = i - j + 1;
                
                int sum;
                if (j > 0)
                    sum = dp[j - 1] + maxi * len;
                else
                    sum = maxi * len;
                
                if (sum > dp[i])
                    dp[i] = sum;
            }
        }
        
        return dp[n - 1];
    }
};
