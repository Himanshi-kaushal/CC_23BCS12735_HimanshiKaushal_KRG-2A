class Solution {
public:
    bool possible(vector<int>& nums, int maxOperations, int mid) {
        long long operations = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            operations += (nums[i] - 1) / mid;
            if (operations > maxOperations) {
                return false;
            }
        }
        
        return true;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1;
        int high = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > high) {
                high = nums[i];
            }
        }

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (possible(nums, maxOperations, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};
