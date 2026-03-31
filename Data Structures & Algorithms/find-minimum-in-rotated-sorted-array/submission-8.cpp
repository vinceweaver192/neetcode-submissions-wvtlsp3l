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

        while (l <= r) {
            int mid = r - l; //l + (r - l) / 2;

            // check mid
            if (nums[mid] < nums[l] && nums[mid] < nums[mid-1]) {
                return nums[mid];
            }
            else {
                if (nums[mid] > nums[l]) {
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
        }
        return nums[0]; // is sorted
    }
};
