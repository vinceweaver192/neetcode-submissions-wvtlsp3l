class Solution {
public:
    // store visited
    vector<vector<bool>> visited;

    int numIslands(vector<vector<char>>& grid) {
        // resize
        visited.resize(grid.size(), vector<bool>(grid[0].size(), false));

        int count = 0;

        // iterate over every row and col, then call dfs, count all occurences
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                // count only if grid is "1"
                if (grid[r][c] == '1' && visited[r][c] == false) {
                    // call dfs
                    dfs(grid, r, c);
                    count++;
                }
            }
        }

        return count;
    }

    void dfs(vector<vector<char>>& grid, int r, int c) {
        // base case, boundary
        if (r >= grid.size() || r < 0 || c >= grid[0].size() || c < 0) {
            return ;
        }

        // ensure only directional 1s are chosen
        if (grid[r][c] == '0') {
            return ;
        }

        if (visited[r][c] == true) {
            return ;
        }

        // set true
        visited[r][c] = true;

        // traverse all 4 directions
        dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r, c - 1);

        return;
    }
};
