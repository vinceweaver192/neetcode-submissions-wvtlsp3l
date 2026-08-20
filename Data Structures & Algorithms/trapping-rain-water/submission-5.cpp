class Solution {
public:
    int trap(vector<int>& height) {
        // 2 pointer l and r, meet in middle, calc side with lower max
        int l = 0, r = height.size()-1;

        int lmax = height[l], rmax = height[r];

        int result = 0;

        while (l < r) {
            if (lmax < rmax) {
                l++;
                result += max(lmax - height[l], 0);
                lmax = max(lmax, height[l]);
            }
            else {
                r--;
                result += max(rmax - height[r], 0);
                rmax = max(rmax, height[r]);
            }
        }

        return result;
    }
};
