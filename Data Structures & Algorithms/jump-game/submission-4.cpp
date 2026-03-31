class Solution {
public:
    bool canJump(vector<int>& nums) {
        // solve backwards with dp

        vector<bool> dp(nums.size(), false);

        // set last to true
        dp[nums.size() - 1] = true;

        // traverse backwards
        for (int i = nums.size()-2; i >= 0; i--) {
            // iterate over the value of nums[i]
            for (int j = i + 1; j < i + nums[i] + 1; j++) {
                // MUST check to ensure that the number nums[j] isnt over the size of nums.size()
                // and check if dp[j] == true, then set dp[i] to true
                if (j < nums.size() && dp[j] == true) {
                    dp[i] = true;
                    break;
                }
            }

        }

        return dp[0];

        // greedy solution
        // 
        // - traverse backwards and set the new target index
        // - target will equal the max jump to reach goal
        // int target = nums.size()-1;

        // for (int i = nums.size() - 2; i >= 0; i--) {
        //     if (nums[i] + i >= target) {
        //         target = i;
        //     }
        // }

        // return target == 0;
    }
};
