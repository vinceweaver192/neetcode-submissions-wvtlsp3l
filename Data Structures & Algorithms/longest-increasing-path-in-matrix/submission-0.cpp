class Solution {
public:
    // create global variables for directions and dynamic progrmming 2D vector to be used in DFS helper function
    vector<vector<int>> dir = {
        {0,1},{0,-1},{1,0},{-1,0}
    };// right, left, down, up

    vector<vector<int>> dp;

    // dfs function parameters:
    // 1. current row and col
    // 2. the matrix
    // 3. the previous val within the path (int)
    int dfs(vector<vector<int>> & matrix, int row, int col, int prevVal) {
        // RULE:
        // - whenever any list/vector of 2D appears, always extract row and col variables
        int rows = matrix.size();
        int cols = matrix[0].size();

        // perform base case check
        // 1. if out of bounds
        //    - this will handle all traversal directions
        // 2. if current val in matrix is smaller than previous 
        //    - traversal will try all directions since this will be the main check
        if (row < 0 || col < 0 || row >= rows || col >= cols || matrix[row][col] <= prevVal) {
            return 0;
        }

        // at this point, val in matrix is larger (good), can update dp[] and perfor recursive dfs()

        // check if the current spot in the matrix has already been computed:
        // PURPOSE:
        // - the reason we want to return the current value is for 'memoization' or, avoiding redundant calculations
        if (dp[row][col] != -1) {
            // if true then trust the current calculated value and return it
            // - IMPORTANT: every value in dp[] that isnt -1 is already a calculated longest path
            // - IMPORTANT: returning a value in a recursive function terminates that recursion
            return dp[row][col]; 
        }

        // at this point, the val in the matrix is a -1 and needs to be calculated in all directions

        // initialize path starting value: 1
        int path = 1;

        // iterate through all directions:
        // - at the end of this loop, path will have the largest path value of its respective starting square (row x col)
        for (auto d : dir) {
            // try all paths recursively and return the max of either the current max path or new max path
            // *** MUST add + 1 to the dfs return ***
            //     - Reasoning:
            //       o 'path' is the only return variable/value, and since this is where we are doing the traversal,
            //         this is also where we should be counting the times it is successful and saving it inside 'path'
            //         and later storing it inside dp[] 
            path = max(path, 1 + dfs(matrix, row + d[0], col + d[1], matrix[row][col]));
        }

        // now post traversal, 
        // 1. update current dp[] square with the current calculated longest increasing path
        //    for this (and each) value in the matrix
        // 2. return this row, col path 
        dp[row][col] = path;
        return path;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        // extract the size of the matrix into rows and cols
        int rows = matrix.size();
        int cols = matrix[0].size();

        // initialize dp with the correct rows x cols
        dp = vector<vector<int>>(rows, vector<int>(cols, -1));

        // create int to store the longest increasing path LIP
        int result = 0;

        // worst case, every value in the matrix could be all the same value and fail to use DFS traversal
        // Therefore, iterate through all rows and cols to ensure each node is visited and calculated in dp[]
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                // compare the current ran dfs result with the previous max path result and store it
                // Parameters:
                // - pass in the matrix to be used in traversing
                // - pass in the current row and col (self explanatory)
                // - pass in a null smallest int val
                result = max(result, dfs(matrix, r, c, INT_MIN));
            }
        }
        // return the longest increasing path
        return result;
    }
};
