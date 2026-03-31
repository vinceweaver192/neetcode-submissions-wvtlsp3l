class Solution {
public:
    vector<vector<int>> dp;

    int rob(vector<int>& nums) {
        // solution, set a flag to determine if the first house is picked or not (1 if yes)
        
        int n = nums.size();

        if (n == 1) {
            return nums[0];
        }
        
        // resize
        dp.resize(n, vector<int>(2, -1));

        // dfs
        return max(dfs(0, 1, nums), dfs(1, 0, nums));
    }

    int dfs(int i, int flag, vector<int>& nums) {
        // base case
        if (i >= nums.size() || (flag == 1 && i >= nums.size() - 1)) {
            return 0;
        }

        // memo
        if (dp[i][flag] != -1) {
            return dp[i][flag];
        }

        // traverse
        dp[i][flag] = max(dfs(i + 1, flag, nums), nums[i] + dfs(i + 2, flag, nums));

        return dp[i][flag];
    }
};
