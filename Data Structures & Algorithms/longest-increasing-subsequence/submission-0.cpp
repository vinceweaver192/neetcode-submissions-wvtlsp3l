class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // use dp backwards from size of nums
        vector<int> dp(nums.size(), 1);

        //int LIS = dp[nums.size()];

        for (int i = nums.size(); i >= 0; i--) {
            // for second loop, we must apply the current i to all the indices we previously counted
            for (int j = i + 1; j < nums.size(); j++) { // i + 1 == the one to the right, we are traversing to the right
                // update dp[j] counts for all
                if (nums[j] > nums[i]) {
                    dp[i] = max(dp[j] + 1, dp[i]);
                }
                // check for LIS
                //LIS = max(LIS, dp[j]);
            }
        }
        int LIS = *max_element(dp.begin(), dp.end());
        return LIS;
    }
};
