class Solution {
public:
    bool canJump(vector<int>& nums) {
        // // solve backwards with dp

        // vector<bool> dp(nums.size(), false);

        // // set last to true
        // dp[nums.size() - 1] = true;

        // // traverse backwards
        // for (int i = nums.size()-2; i >= 0; i--) {
        //     // ensure the length is not going over
        //     if (nums[i] + i <= nums.size()) {
        //         dp[i] = dp[nums[i] + i];
        //     }
        // }

        // return dp[0];

        // greedy solution
        // 
        // - traverse backwards and set the new target index
        // - target will equal the max jump to reach goal
        int target = nums.size()-1;

        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] + i >= target) {
                target = i;
            }
        }

        return target == 0;
    }
};
