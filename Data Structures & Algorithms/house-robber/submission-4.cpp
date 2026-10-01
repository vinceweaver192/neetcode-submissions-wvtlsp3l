class Solution {
public:
    int rob(vector<int>& nums) {
        // every current house will be the max up to that point
        // can either take and take the prev non neighbor OR not take and extend the prev neighbors
        const int size = nums.size();
        vector<int> dp(size + 2, 0); // + 2 to look at prev non neighbor

        for (int i = 0; i < size; i++) {
            dp[i+2] = max(nums[i] + dp[i], dp[i+1]);
        }

        return dp[size+1];
    }
};
