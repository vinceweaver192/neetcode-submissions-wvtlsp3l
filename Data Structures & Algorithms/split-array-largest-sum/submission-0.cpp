class Solution {
private:
    bool canSplit(vector<int>& nums, int k, int cap) {
        int sum = 0;
        int splitCount = 1;

        for (int num : nums) {
            if (sum + num <= cap) {
                sum += num;
            }
            else {
                sum = num;
                splitCount++;
            }
        }

        return splitCount <= k;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        // upper bound = sum
        // lower bound = max
        // binary search the capacity for each split
        int upper = 0;
        int lower = 0;

        for (int num : nums) {
            upper += num;
            lower = max(lower, num);
        }

        while (lower < upper) {
            const int mid = (upper - lower) / 2 + lower;

            if (canSplit(nums, k, mid)) {
                upper = mid; // see if we can go lower
            }
            else {
                lower = mid + 1;
            }
        }

        return upper;
    }
};