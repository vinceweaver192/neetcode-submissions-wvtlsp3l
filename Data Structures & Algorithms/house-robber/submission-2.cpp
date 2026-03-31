class Solution {
public:
    vector<int> dp;

    int rob(vector<int>& nums) {
        dp.resize(nums.size(), -1);

        // call dfs
        return dfs(0, nums);
    }

    int dfs(int l, vector<int>& nums) {
        // check if l is out of bounds
        if (l >= nums.size()) {
            return 0;
        }
        // check memoization
        if (dp[l] != -1) {
            return dp[l];
        }

        // 2 cases:
        // 1. we rob the next house ONLY (+1)
        // 2. we rob the current house and the NEXT next house (+2)
        dp[l] = max(dfs(l+1, nums), nums[l] + dfs(l+2, nums));

        return dp[l];
    }
};
