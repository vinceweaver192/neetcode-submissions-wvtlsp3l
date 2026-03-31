class Solution {
public:
    int trap(vector<int>& height) {
        // check left and right pointers and calc maxes
        int l = 0;
        int r = height.size()-1; // inclusive index

        // initialize the maxes with their respective values
        int lMax = height[l];
        int rMax = height[r];

        int results = 0;

        while (l < r) {
            // check which size is the bottle neck
            if (lMax < rMax) {
                // move left side
                l++;

                // find the left max
                lMax = max(lMax, height[l]);

                // calculate rainwater diff
                // - to avoid negative values, get the difference of
                //   the left max - current height OR 0 if negative
                results += max(lMax - height[l], 0);
            }
            else {
                // move right side
                r--;

                rMax = max(rMax, height[r]);

                results += max(rMax - height[r], 0);
            }
        }
        return results;
    }
};
