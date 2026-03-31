class Solution {

public:

    // Solution Approach:
    // 1. Start with the "brute force" Top-Down method:
    //    - if a '*' exist in the pattern 'p', check and make a decision:
    //      o first is whether to use the '*' and continue counting duplicate chars
    //      o Second is dont use the '*' and dont take the char
    // 2. Use DFS to iteratively check characters from both strings by passing 
    //    in the current index for each string
    // 3. Add memoization dp 2D array (storing i,j pairs) once the brute force is working

    // * Add a dynamic programming memoization to improve efficiency and remove redundant calculations in DFS
    // create a 2D vector of int to store the true/false results from each char in both string 's' and 'p'
    // *** CANT use a bool, dp needs -1 to check if index has been calculated before ***
    vector<vector<int>> dp; // global var can be used anywhere

    bool isMatch(string s, string p) {
        // get the sizes of the 2 strings
        int m = s.size(), n = p.size();

        // initialize dp with -1 vals to see if val hasnt been calculated or not (cant use bool)
        // use vector.assign() ALWAYS to initialize any vector with values
        dp.assign(m + 1, vector<int>(n + 1, -1));

        // recursively call dfs with these parameters:
        // 1. starting index for 's' and 'p': i, j
        // 2. sizes of 's' and 'p': m, n
        // 3. the strings 's' and 'p'
        return dfs(0, 0, m, n, s, p);
    }

private:
    bool dfs(int i, int j, int m, int n, string& s, string& p) {
        // base case(s):
        // 1. if the index for pattern p has reached the end, then check if string s has also reached its end
        if (j == n) { // if j's index is n, then it has gone + 1 above the string and is out of bounds (reached its end)
            // if true, return if i also equals its end m
            return i == m;
        }
        // 2. check for memoization base case: if dp[i][j] != -1 (already calculated)
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // At this point, can now perform matching

        // Rules for a match:
        // 1. index 'i' must be smaller than the size 'm'
        // 2. s[i] can match p[j] OR
        // 3. "." can also match p[j]
        //
        // IMPORTANT:
        // - since type is a bool, value matching results can be compared and used to store into var 'match'
        // - Ex. the result of this match or mismatch will be default 'true' or 'false', and the statement
        //   itself can take advantage of this without ever specifying 'set match == true' or vice versa
        bool match = (i < m) && (s[i] == p[j] || p[j] == '.');

        // handle the "*" syntax: (check if "*" is in pattern FIRST)
        // 1. check if j + 1 is within bounds of n
        // 2. check if p[j+1] == "*"
        if (j + 1 < n && p[j+1] == '*') {
            // Since the next char in the pattern IS a "*", we need to handle 2 cases and return the result:
            // 1. skip the current character and its "*" in the pattern ONLY:
            //    - i stays the same, j + 1 + 1 (1 for the current char, and 1 for the "*" char)
            // 2. use the "*" to match with 1 or multiple duplicate chars of the current char
            //    - i + 1, j stays the same (iterate over string with index i)
            // return (dfs(i, j+2, m, n, s, p) || 
            //        (match && dfs(i+1, j, m, n, s, p))); // 1st statement is 1st case and 2nd statement is 2nd case
            //
            // replace return with dp[i][j] 
            dp[i][j] = (dfs(i, j+2, m, n, s, p) || 
                       (match && dfs(i+1, j, m, n, s, p)));
            // return dp[i][j];
            // *** Since we are now storing values inside the dp[][] memoization list, we can just call the one return at the very end ***
        }
        else {
            // if here, then no "*" exist at this current char in pattern 'p'
            // - can now perform single character matching as usual

            // Case 3:
            // - compare the results of match (true or false) with the results from the next dfs traversal with:
            //   o i + 1 (to go to next value) AND
            //   o j + 1 (to go to next value)
            // return (match && dfs(i + 1, j + 1, m, n, s, p));
            //
            // same here, replace return with dp[i][j] THEN return
            dp[i][j] = (match && dfs(i + 1, j + 1, m, n, s, p));
            // return dp[i][j];
            // *** Since we are storing the correct value inside dp[i][j], we only need to return dp[i][j] ONCE at the very end ***
        }

        // outside of all cases, if here and match was not returned earlier, then there exist no match, return false
        // return false;
        // 
        // only need to return the current value in dp
        return dp[i][j];
    }
};
