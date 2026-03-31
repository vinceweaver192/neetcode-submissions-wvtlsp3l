class Solution {
public:
    int trap(vector<int>& height) {
        // Optimal Solution: (O(n) time complexity and O(1) space)
        // height = [0,2,0,3,1,0,1,3,2,1]
        //               ^           ^
        // *** When l and r progress closer together, they already store the highest values 
        //     of their left and rights and only need to subtract their l or r side maxes with
        //     the current heights and add to results
        //
        // *** Must also check for negative values prior as well
        //
        //          
        // For trapping water, we only need to focus on the minimums
        // of max lefts and max rights heights
        //
        // For example, Max L:       0, 2
        //              Max R:       1, 1
        //              Total Rain:  0,  
        // 
        // TODO:
        // 1. Use 2 pointers to keep track of the left index and right index (l and r == indices)
        //    - Traverse each indices inward (l++ and r-- == indices)
        //    - When you move a l and r, calculate its water using 'result += maxLeft - height[l]'
        // 3. Keep track of left max height and right max height (lmax and rmax == heights)
        // 4. 
        //
        // while (left_idx < right_idx)
        // 
        // 
        // Since left is the bottleneck (it is smaller), we need to 
        // move it along

        // edge case
        if (height.empty()){
            return 0;
        }

        int l = 0;
        int r = height.size() - 1;
        int rightMax = height[r];
        int leftMax = height[l];

        int result = 0;

        while (l < r){
            // decide whih side to traverse first based on bottleneck
            // l or r
            // check heights of current positions:
            if (height[l] < height[r]){
                // do left side operations
                // 1. move l index counter => l++
                // 2. check if water can be filled in current position

                // get updated max of left boundary and store it
                leftMax = max(leftMax, height[l]);

                int lwater = leftMax - height[l];
                lwater = max(lwater, 0); // remove negative values
                result += lwater;
                l++;
            }
            else { // height[l] >= height[r]
                // do right side operations
                // 1. move r index counter => r--
                // 2. check if water can be filled in current position

                // get updated max of right boundary and store it
                rightMax = max(rightMax, height[r]);

                int rwater = rightMax - height[r];
                rwater = max(rwater, 0); // remove negative values
                result += rwater;
                r--;
            }
        }
        return result;
    }
};
