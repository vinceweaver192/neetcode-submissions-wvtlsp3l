class Solution {
public:
    int trap(vector<int>& height) {
        const int size = height.size();

        int lmax = height[0];
        int rmax = height[size-1];

        int l = 0, r = size-1;
        int result = 0;

        while (l < r) {
            if (lmax <= rmax) {
                l++;
                lmax = max(lmax, height[l]);
                result += lmax - height[l];
            }
            else {
                r--;
                rmax = max(rmax, height[r]);
                result += rmax - height[r];
            }
        }

        return result;
    }
};