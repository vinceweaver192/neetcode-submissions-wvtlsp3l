class Solution {
private:
    vector<vector<bool>> visited;

    int countIsland(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) 
            return 0;

        if (visited[i][j] == true || grid[i][j] != 1)
            return 0;

        visited[i][j] = true;
        return (countIsland(grid, i+1, j) + countIsland(grid, i-1, j) +
                countIsland(grid, i, j+1) + countIsland(grid, i, j-1) + 1);
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int x = grid.size();
        int y = grid[0].size();

        visited.resize(x, vector<bool>(y, false));

        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                if (grid[i][j] == 1 && !visited[i][j])
                    maxArea = max(maxArea, countIsland(grid, i, j));
            }
        }

        return maxArea;
    }
};
