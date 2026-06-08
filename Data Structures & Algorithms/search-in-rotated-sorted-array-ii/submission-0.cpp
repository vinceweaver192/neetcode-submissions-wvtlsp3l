class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // binary search:
        // 2 choices?
        // if it is unclear to go left or right, decrement r by 1 and try again
        const int n = nums.size();
        int l = 0; 
        int r = n - 1;

        while (l <= r) {
            const int mid = (r - l) / 2 + l;

            if (nums[mid] == target) {
                return true;
            }
            else if (nums[l] == nums[r]) {
                r--; // check all
            }
            else if (nums[l] <= nums[mid]) { // left side sorted
                if (nums[mid] > target && target >= nums[l]) {
                    // check left
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
            else {
                // right side sorted
                if (nums[mid] < target && target <= nums[r]) {
                    // check right
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
        }

        return false;
    }
};