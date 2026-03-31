class Solution {
public:
    int search(vector<int>& nums, int target) {
        // TODO:
        // 1. Determine which side partition is sorted:
        //    - if middle is greater than left, then left is sorted and can be binary searched
        //    - if middle is less than left, then right is sorted and can be binary searched
        //    * in both cases, there can still be lingering values that the target can be equal to *
        // 2. Since now we know which side is sorted, we can search for the target:
        //    - if the left side is sorted, check if the target 
        //      o is greater than middle (handles lingering cases where middle is not the highest val: ex. 4,5,6,7,3 : target can be 7 but mid will be 6)
        //      o is greater than left most val (handles every case where left > all rotated values on the right partition)
        // 3. Will be the same as previous except for the RIGHT sorted side:
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            // base case
            if (nums[mid] == target) {
                return mid;
            }

            // 1. check which side is sorted
            // *** GOTCHA ***
            //     - be sure 
            if (nums[l] <= nums[mid]) {
                // 2. left sorted
                // check for 2 conditions
                if (target > nums[mid] || target < nums[l]) {
                    // search right side
                    l = mid + 1;
                }
                else {
                    // search left sorted side
                    r = mid - 1;
                }
            }
            else {
                // 3. right sorted
                // check for 2 conditions
                if (target < nums[mid] || target > nums[r]) {
                    // search left
                    r = mid - 1;
                }
                else {
                    // search right sorted side
                    l = mid + 1;
                }
            }
        }

        return -1;
    }
};
