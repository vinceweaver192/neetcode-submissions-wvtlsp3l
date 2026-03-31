class Solution {
public:
    int maxArea(vector<int>& heights) {
        // store results
        int maxSum = INT_MIN;

        int l = 0, r = heights.size() - 1;

        // iterate while l < r
        while (l < r) {
            // calculate heights:
            // 1. get the min of the 2 heights
            // 2. multiply by the difference of distance between height[l] and heght[r]
            // 3. compare max() of current max and new sum
            
            int dist = r - l; // GOTCHA *** just do simple distance calculation, no need for exact median, r - l will suffice
            int sum = min(heights[l], heights[r]) * dist;
            maxSum = max(maxSum, sum);

            // increment the bottleneck
            if (heights[l] < heights[r]) {
                l++;
            }
            else { // (heghts[l] > heights[r]) {
                r--;
            }
        }

        return maxSum;
    }
};
