class Solution {
public:
    void sortColors(vector<int>& nums) {
        // l : everything left should be 0, l is the first non zero
        // r : everything right should be 2, r is the first non 2
        int l = 0;
        int r = nums.size()-1;

        int iter = 0;
        while (iter <= r) {
            if (nums[iter] == 0) {
                swap(nums[iter], nums[l]);
                l++;
                iter++;
            }
            else if (nums[iter] == 2) {
                swap(nums[iter], nums[r]);
                r--;
            }
            else {
                iter++;
            }
        }
    }
};