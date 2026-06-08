class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int m = matrix.size();
        const int n = matrix[0].size();

        // rows
        int top = 0;
        int bottom = m-1;

        // cols
        int l = 0;
        int r = n-1;

        // find row
        int row;
        while (top <= bottom) {
            row = (bottom - top) / 2 + top;

            if (target >= matrix[row][l] && target <= matrix[row][r]) {
                break;
            }
            else if (target < matrix[row][l]) {
                // move r and bottom to mid
                bottom = row - 1; // still need to check row
            }
            else {
                top = row + 1;
            }
        }

        // find col
        while (l <= r) {
            const int col = (r - l) / 2 + l;

            if (matrix[row][col] == target) {
                return true;
            }
            else if (target > matrix[row][col]) {
                l = col + 1;
            }
            else {
                r = col - 1;
            }
        }
        return false;
    }
};
