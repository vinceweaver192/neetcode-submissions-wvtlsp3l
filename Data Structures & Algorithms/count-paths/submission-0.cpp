class Solution {
public:
    int uniquePaths(int m, int n) {
        // if the square i 1x1 then we should be in the start and end, only return 1
        // dp = start = 1
        // return dp[m-1][n-1]

        // calc top and left borders first, start at 1x1, dp[i][j] = dp[i-1][j] + dp[i][j-1]

        vector<vector<int>> dp(m, vector<int>(n, 1));

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }
};
