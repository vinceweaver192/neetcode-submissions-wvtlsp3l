class Solution {
private:
    int robRange(vector<int>& nums, int left, int right) {
        int prev1 = 0;
        int prev2 = 0;

        for (int i = left; i <= right; i++) {
            int curr = max(nums[i] + prev2, prev1);

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }

public:
    int rob(vector<int>& nums) {
        const int size = nums.size();
        if (size == 1)
            return nums[0];
        // 2 ranges, 1 includes the first index but ignores the last
        // the other ignores the first index and includes the last
        return max(robRange(nums, 0, size-2), robRange(nums, 1, size-1)); 
    }

};
