class Solution {
public:
    vector<int> dp;

    int climbStairs(int n) {
        // use memoization and recursion

        // resize dp to all -1's for comparison of calc values in dfs
        dp.resize(n, -1);

        // pass in end point and starting index (0)
        return dfs(n, 0);
    }

    int dfs(int n, int i) {
        // base case
        if (i == n) {
            return 1;
        }
        if (i > n) {
            // overshot, return 0
            return 0;
        }

        // memoization
        if (dp[i] != -1) {
            return dp[i];
        }

        // traverse and return/update dp
        dp[i] = dfs(n, i + 1) + dfs(n, i + 2);

        return dp[i];
    }
};
