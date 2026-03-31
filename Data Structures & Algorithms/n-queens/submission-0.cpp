class Solution {
public:

    // General Solution Approach Rule:
    // - queens must not be on the same row
    // - queens must not be on the same column
    // - queens must not be on the same positive or negative diagnols
    // * the diagnols can be calculated by:
    // 1. positive diagnols being: row + col (different diagnols have unique offsets, true for pos and neg diags)
    // 2. negative diagnols being: row - col

    // create global variable unordered sets to store:
    // 1. the columns (must be unique per queen)
    // 2. positive diagnol
    // 3. negative diagnol
    unordered_set<int> col;
    unordered_set<int> posDiag;
    unordered_set<int> negDiag;

    // since we return a 2D vector board, create a 2D result[]
    vector<vector<string>> result;


    vector<vector<string>> solveNQueens(int n) {
        // create 1D empty board of size n queens
        // 'n' strings of size 'n', initialized to '.'
        vector<string> board(n, string(n, '.'));

        // call backtrack helper function
        backtrack(0, n, board);

        // return result board of all valid 1D solutions
        return result;
    }

private:
    // create helper backtrack()
    // recursive function meant to place queens row by row
    void backtrack(int r, int n, vector<string> & board) {
        // base case
        // if queens have been placed in all rows, add board to results
        if (r == n) {
            // number of rows is equal to the number of queens
            result.push_back(board);
            return;
        }

        // iterate over each column in the current row
        // try every column for every row, and for each recursive row call(), try inserting a Queen in every column of that row
        for (int c = 0; c < n; c++) {
            // check if:
            // - the queens are targeting each other diags
            // - the queens are stacked in the same column (c will iterate over the x-axis and each must be unique)
            // * no need to check row since we are emplacing one queen per row as we iterate
            if (col.count(c) || posDiag.count(r + c) || negDiag.count(r - c)) {
                // if any of these are true...
                continue; // skip this position and move to next
            }

            // at this point, the queen can be emplaced with a 'Q'

            // add 'c' index to col set()
            col.insert(c);
            // add the current 'c' index to the pos and neg diag
            posDiag.insert(r + c);
            negDiag.insert(r - c);

            // place 'Q' to board
            board[r][c] = 'Q';

            // recursively call backtrack() and increment the current row by 1
            backtrack(r + 1, n, board);

            // reset this currently added queen 'Q' and try a different column placement but in the same row 
            // * will do this for each and every column index in every row, until all combinations have been tried
            col.erase(c);
            posDiag.erase(r + c);
            negDiag.erase(r - c);
            board[r][c] = '.';
        }
    }
};
