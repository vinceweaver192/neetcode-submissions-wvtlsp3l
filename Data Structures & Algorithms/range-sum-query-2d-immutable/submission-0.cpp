class NumMatrix {
private:
    vector<vector<int>> prefSum;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        prefSum.resize(m + 1, vector<int>(n + 1, 0)); // +1 to avoid manual boundary check
        // 1s indexed

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // add only from above and to the left
                // * MUST subtract the double counted area
                prefSum[i+1][j+1] = matrix[i][j] + prefSum[i][j+1] + prefSum[i+1][j] - prefSum[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int bottomRight = prefSum[row2+1][col2+1]; // inclusive
        // subtract above and left, but add back top left since it got double counted
        int top = prefSum[row1][col2+1]; // exclusive of square row but match column
        int left = prefSum[row2+1][col1]; // exclusive of square column but match row
        int topLeft = prefSum[row1][col1];
        return bottomRight - top - left + topLeft;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */