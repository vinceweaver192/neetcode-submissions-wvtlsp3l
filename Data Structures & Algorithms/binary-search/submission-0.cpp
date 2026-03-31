class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right){
            //int mid = left + ((right - left) / 2);
            int mid = ((left + right) / 2);
            if (nums[mid] == target){
                return mid;
            }
            if (nums[mid] < target){
                // skip all left side, update left pointer
                left = mid + 1;
            }
            if (nums[mid] > target){
                // skip all right side, update rght pointer
                right = mid - 1;
            }
        }
        return -1;
    }
};
