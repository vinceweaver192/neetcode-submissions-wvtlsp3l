// Solution Explanation:
//
// dp:
// - use a vector bottom-up approach
//
// bottom-up approach:
// - starting with index 0, loop "amount" number of times
// - Reasoning:
//   o to do a bottom-up approach, we need to start from index 0
//     - ex: dp[0] = 0, dp[1] = (-1 if no amount of coins fit), dp[2] = # of 
//           available coins that add up to 2... dp[amount] = solution
//   o dp[amount] => will equal amount+1 if a solution was never found
// - Important Calculation:
//   o we calculate dp[i] = min(dp[i - coin] + 1, dp[i]);
//     - before this, we want to make sure i - coin is not negative
//     - 

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1); // size, vals

        // start with 0 = 0
        dp[0] = 0;

        // start at 1 
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins){
                if (i - coin >= 0) {
                    dp[i] = min(dp[i - coin] + 1, dp[i]);
                }
            }
        }
        if (dp[amount] > amount) {
            return -1;
        }
        return dp[amount];
    }
};
