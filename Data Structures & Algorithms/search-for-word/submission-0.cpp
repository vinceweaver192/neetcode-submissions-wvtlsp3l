class Solution {
public:
    vector<vector<bool>> visited;

    bool exist(vector<vector<char>>& board, string word) {
        // set all values to -1 for unvisited
        visited.resize(board.size(), vector<bool>(board[0].size(), false));

        // iterate over every row and colum
        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[0].size(); c++) {
                if (dfs(board, word, r, c, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string word, int r, int c, int index) {
        // base case, check if i == word.size()
        if (index == word.size()) {
            return true;
        }

        // base case, boundary
        if (r >= board.size() || r < 0 || c >= board[0].size() || c < 0) {
            return false;
        }

        // check visited
        if (visited[r][c] == true) {
            return false;
        }

        // set visited to true
        visited[r][c] = true;

        bool res = false;

        // check current letter for a match
        if (board[r][c] == word[index]) {
            // traverse and update result
            res = dfs(board, word, r + 1, c, index + 1) ||
                  dfs(board, word, r - 1, c, index + 1) ||
                  dfs(board, word, r, c + 1, index + 1) ||
                  dfs(board, word, r, c - 1, index + 1);
            // will store any true that comes up
        }
        // undo backtrack visit
        visited[r][c] = false;

        return res;
    }
};
