class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // create 3 hashmaps
        // 1. for mapping the rows
        // 2. for mapping the cols
        //    - both row and col maps will store sets of all unique numbers OR dots '.'
        // 3. for mapping the 3x3 squares
        //    - will map x,y grid to each unique 3x3 square set of chars
        // * purpose is to store unique, non duplicate values
        unordered_map<int, unordered_set<char>> rows, cols; // steps 1 and 2

        map<pair<int, int>, unordered_set<char>> squares; // 3x3

        // iterate over each row
        for (int row = 0; row < board.size(); row++) {
            // iterate over each col
            for (int col = 0; col < board[0].size(); col++) {
                // skip empty cells
                if (board[row][col] == '.') {
                    continue; // loop to next val
                }

                // if here, then board is a num char

                // identify the 3x3 grid using integer division and compartmentalize values into their respective squares
                // - Ex. squareKey will store values into {row: 0, 1, 2 ; col: 0, 1, 2} => {0,0 OR 1,0, ... 2,2} (9 squares total)
                // - we take advantage of division rounding numbers down:
                //   o Ex. indices are 0 - 8 (9 numbers) and 8/3 => 2, 0/3 => 0, and 2/3 => 0
                //   o rows: 0 1 2 | 3 4 5 | 6 7 8 (same layout for cols)
                pair<int,int> squareKey = {row / 3, col / 3};

                // now before we insert ANYTHING into maps, check if the current number already exists in the respective:
                // 1. row map of sets
                // 2. col map of sets
                // 3. square map of sets
                if (rows[row].count(board[row][col]) || 
                    cols[col].count(board[row][col]) ||
                    squares[squareKey].count(board[row][col])) {
                    
                    // if any of these are true, then return false
                    return false;
                }

                // can now insert into all 3 maps
                rows[row].insert(board[row][col]);
                cols[col].insert(board[row][col]);
                squares[squareKey].insert(board[row][col]);
            }
        }
        // if list have terminated and no false returns have occured, then return true
        return true;
    }
};
