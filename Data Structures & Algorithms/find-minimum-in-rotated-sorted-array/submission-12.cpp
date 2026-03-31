class Solution {
public:
    int findMin(vector<int> &nums) {
        // TODO: Binary Search
        // 1. check if 
        //    o middle is less than left index val
        //    o AND val to the left is greater than current middle val
        //      - if yes, return the val
        //      - if not, then adjust left/right
        // 2. at the end, (list must be sorted) => return nums[0]
        int l = 0;
        int r = nums.size() - 1;

        while (l < r) {
            // only need to calculate difference, no need to find middle
            int mid = l + (r - l) / 2;

            // check mid
            if (nums[mid] < nums[r]) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return nums[l]; // is sorted
    }
};
