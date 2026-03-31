class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        // get size of grid (square grid so only 1 side is necessary)
        int N = grid.size(); // NxN

        // create the visited set but must include x, y coordinates
        // CANNOT be an unordered_set for pairs
        set<pair<int,int>> visited;

        // create the min heap
        // Syntax:
        // 1. create a min heap where each value is a vector/list type
        // 2. each value list in the queue will be queue'd in order of smallest elevation and include the x, y coordinates
        //    - Ex. {elevation #, row #, col #}, {...}, {...}, ...
        // 3. the queue is responsible for pushing and stacking current paths, as well as popping paths that have been 
        //    updated with higher elevations
        priority_queue<vector<int>, vector<vector<int>>, greater<>> minHeap;

        // for simplicity, define all possible directions in a 2D list/vector
        vector<vector<int>> directions = {
            {0,1}, {0,-1}, {1,0}, {-1,0}
            }; // right, left, down, up (in-order)

        // push starting 0,0 value into minHeap
        minHeap.push({grid[0][0],0,0});

        // mark starting cell as visited
        visited.insert({0,0});

        // can now implement dijkstra's algorithm (iterative BFS ***WEIGHTED***)

        // process all values in minHeap until minHeap is empty
        while (!minHeap.empty()) {
            // get current top of heap (smallest elevation time)
            // use 'auto' type to grab values that are pairs, can also use vector since minHeap stores vectors
            auto top = minHeap.top();

            // remove top value from minHeap
            minHeap.pop();

            // extract all partition from top()
            int elevation = top[0], row = top[1], col = top[2];

            // base case
            // if the end is reached (N-1, N-1), then return current elevation
            if (row == N - 1 && col == N - 1) {
                return elevation;
            }

            // begin exploring all possible neighbors, ignoring previously visited grid squares
            // iterate through all 4 directions in the 2D directions vector
            for (const auto & dir : directions) {
                // neighbor row = dir[0] and neighbor col = dir[1]
                // MUST add the current row and col to each direction
                int neiR = row + dir[0];
                int neiC = col + dir[1];

                // check if direction is:
                // 1. is within grid boundaries
                // 2. has already been visited
                if (neiR < 0 || neiR == N || neiC < 0 || neiC == N ||
                visited.count({neiR,neiC})) {
                    // if so, then skip this direction
                    continue;
                }
                // else, add grid square to minHeap and update visited

                // General Notes:
                // - since we created a minHeap, the top value will always be the smallest value, but may be updated to a larger value
                //   as we traverse along the path to the end.
                // - We will push all valid grid square values to the minHeap, but pop() smaller values as we iterate
                // - Must also keep track of the larger of the 2 values (elevation and current grid[x][y])
                minHeap.push({max(elevation, grid[neiR][neiC]), neiR, neiC});

                // update visited
                visited.insert({neiR, neiC});
            }
        }

        // return the default size
        return N*N;
    }
};
