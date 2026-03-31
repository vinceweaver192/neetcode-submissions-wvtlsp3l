class Solution {
public:
    vector<int> dp;

    int rob(vector<int>& nums) {
        // memoization and dfs
        int n = nums.size();

        dp.resize(n, -1);

        return dfs(nums, 0);
    }

    int dfs(vector<int>& nums, int i) {
        // base case
        cout << "i = " << i << ", ";
        if (i >= nums.size()) {
            return 0;
        }

        if (dp[i] != -1) {
            cout << "dp[" << i << "] = " << dp[i] << endl;
            return dp[i];
        }

        // traverse
        // calculate both dfs ends first
        dp[i] = max(dfs(nums, i + 2) + nums[i], dfs(nums, i + 1));
        cout << "post traversal: " << "dp[" << i << "] = " << dp[i] << endl;
        return dp[i];
    }
};
