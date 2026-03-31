class Solution {
public:
    int maxCoins(vector<int>& nums) {
        // get the size of nums
        int n = nums.size();

        // create a new array to store 2 extra 1's values for boundaries
        vector<int> newNums(n + 2, 1);

        // copy the elements from nums into newNums leaving out a 1 in the beginning and end
        for (int i = 0; i < n; i++) {
            newNums[i + 1] = nums[i];
        }

        // create a 2D dynamic programming array and initialize everything to -1 (memoization)
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));

        // call the dfs helper function:
        // Parameters:
        // 1. newNums -> to traverse a list with 1's at the left and right boundaries
        // 2. starting left idx -> since we skip the first boundary on the left, start index is 1 (0 + 1)
        // 3. starting right idx -> n is the size of the number of elemens in the original balloon list of nums
        // 4. dynamic programming arr[][] -> to update each index with the its current max (stores max subproblems)
        return dfs(newNums, 1, n, dp);
    }

private:
    // dfs helper func
    // return -> will be the number of coins during that iteration
    int dfs(vector<int>& nums, int l, int r, vector<vector<int>>& dp) {
        // base case
        // 1. check if left pointer surpassed the right pointer
        //    - the last node will have both left and right ptrs at the same idx, after that last iteration l > r
        // 2. check for memoization in dp (value != -1)
        if (l > r) { 
            // return 0 since this is the end of the subproblems and there is no valid idx here, return 0 coins
            return 0;
        }
        if (dp[l][r] != -1) {
            // if already calculated, then return the same val
            return dp[l][r];
        }

        // at this point, indices are good

        // initialize current dp[l][r] to 0 representing no coins currently calculated
        dp[l][r] = 0;

        // iterate from left ptr to right ptr INCLUSIVELY without modifying current l or r ptrs
        for (int i = l; i <= r; i++) {
            // calculate balloon coins: nums[l - 1] * nums[i] * nums[r + 1]
            // Reasoning:
            // 1. ALWAYS be sure to calculate the left and right OF THE BOUNDARIES first
            // 2. the purpose is to trust the algorithm and iterate over every value
            int coins = nums[l - 1] * nums[i] * nums[r + 1];

            // now recurisvely that we calculated the coins split:
            // 1. calculate the recursive call of the left side (right ptr becomes => i - 1, move right ptr to the left)
            // 2. calculate the recursive call of the right side (left ptr becomes => i + 1, move left ptr to the right)
            coins += dfs(nums, l, i - 1, dp) + dfs(nums, i + 1, r, dp);

            // now save the max of the either the current dp[l][r] or the calculated coins
            // - store result back into dp[l][r]
            dp[l][r] = max(coins, dp[l][r]);
        }

        // now return the current max result (which is the current dp[l][r] at this point in time)
        return dp[l][r];
    }
};
