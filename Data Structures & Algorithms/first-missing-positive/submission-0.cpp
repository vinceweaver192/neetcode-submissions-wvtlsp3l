class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // iterate over all numbers and move them into their correct positive position
        // the first number that is NOT in its designated area will be returned

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
                // Example: 3 != nums[2] -> swap
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // the swap and left->right iteration ensures our values are swapped in the correct places
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        return n + 1; // everything is in order except the last val since it is out of range of the next pos
    }
};