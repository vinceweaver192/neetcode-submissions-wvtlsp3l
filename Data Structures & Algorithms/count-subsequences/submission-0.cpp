class Solution {
public:
    // Solution Approach: (dynamic programming, least common string, DFS)
    // 1. create a 2D dp array of strings [s][t] where:
    //    - each value in the array holds the number of unique combinations of substrings at that point
    //      o the end of the array [n-1][m-1] will store the number of distinct subsequences
    // 2. call DFS with these parameters:
    //    - index 'i' for string 's' used for iterating over 's'
    //    - index 'j' for string 't' used for iterating over 't'
    //    - both strings 's' and 't'
    //      o DFS MUST utilize backtracking/memoization (dp is for memoization)
    vector<vector<int>> dp;

    int numDistinct(string s, string t) {
        // edge case, check size of 's' and 't'
        // - if size s < t then return 0 since its not possible
        int m = s.size(), n = t.size();

        if (m < n) {
            return 0;
        }

        // initialize dp using vector.assign()
        // - set all values to -1 to start
        dp.assign(m + 1, vector<int>(n + 1, -1));

        // call and return dfs
        return dfs(0, 0, s, t);
    }

private:

    // dfs helper func
    int dfs(int i, int j, string& s, string& t) {
        // base case checks:
        // * IMPORTANT *(base case checks are used for main val returns during recursive traversal)
        // 1. check if j has reached size t -> return 1 (index reached end, a distinct solution has been found, add + 1)
        // 2. check if i has reached size s -> return 0 (if this is true, then 'j' hasnt reached end yet, so return + 0)
        // 3. memoization, check if current [i][j] index has already been set to NOT -1 -> return current dp[i][j]
        // * GOTCHA * -> make sure to not check index with size -1
        //    o Reasoning: we still want to iterate over the last value, we want the base case to return once the index has 
        //      gone over the limit
        if (j == t.size()) {
            return 1;
        }
        if (i == s.size()) {
            return 0;
        }
        if (dp[i][j] != -1) { // -1 means the value hasnt been calculated yet
            return dp[i][j];
        }

        // at this point, dfs traversal on ONLY the i index FIRST
        // - create an int to store the dp[][] index value
        int result = dfs(i + 1, j, s, t);

        // now check if s[i] == t[j] -> if so then call dfs on both traversing together
        if (s[i] == t[j]) {
            // also traverse if the characters match
            result += dfs(i + 1, j + 1, s, t);
        }

        // store the result value inside dp at this current index
        dp[i][j] = result;

        // after all calculations have been completed, return the highest accumulated calculation
        // - (which is the total number of distinct subsequences)
        return result;
    }
};
