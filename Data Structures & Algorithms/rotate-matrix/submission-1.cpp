class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Trick: the matrix still maintains [i][j] ordering except they are swapped [j][i]
        //        and j is n-1, so if we utilize a l and r pointer, we can ensure that a full
        //        rotation swap is done when l and r meet (l < r)

        int n = matrix.size();

        int l = 0;
        int r = n - 1;

        // iterate over depth between l and r of n (should get smaller as we move up in the matrix)
        while (l < r) {
            // now iterate over one side n, will need to perform 4 swaps per increment
            for (int i = 0; i < r - l; i++) {
                int top = l;
                int bottom = r;

                // save value to swap with topLeft value
                int bottomLeft = matrix[bottom - i][l];

                // swap bottomLeft
                matrix[bottom - i][l] = matrix[bottom][r - i];

                // swap bottomRight
                matrix[bottom][r - i] = matrix[top + i][r];

                // swap topRight
                matrix[top + i][r] = matrix[top][l + i];

                // swap topLeft
                matrix[top][l + i] = bottomLeft;
            }
            // increment and decrement the boundaries
            l++;
            r--;
        }
    }
};
