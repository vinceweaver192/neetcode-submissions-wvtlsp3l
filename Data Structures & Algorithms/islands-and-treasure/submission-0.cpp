class Solution {
private:
    vector<vector<bool>> visited;
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();

        visited.resize(m, vector<bool>(n, false));

        // add all treasures to a queue
        queue<pair<int,int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) q.push({i,j});
            }
        }

        // bfs and modify all islands around treasure, adding 1 to distance level
        int level = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [x,y] = q.front();
                //int x = p.first;
                //int y = p.second;
                q.pop();

                // check all dirs for grid
                for (auto d : dir) {
                    const int newX = x + d[0];
                    const int newY = y + d[1];
                    if (newX >= m || newX < 0 || newY >= n || newY < 0) continue;

                    if (visited[newX][newY] == true || grid[newX][newY] <= level) continue;

                    visited[newX][newY] = true;
                    grid[newX][newY] = level;
                    q.push({newX, newY});
                }
            }
            level++;
        }
    }
};
