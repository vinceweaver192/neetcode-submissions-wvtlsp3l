class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // sliding window
        // window size is determined by sum >= target

        const int n = nums.size();
        int l = 0;
        int sum = 0;
        int minLength = INT_MAX;
        for (int r = 0; r < n; r++) {
            sum += nums[r];

            while (sum - nums[l] >= target) {
                sum -= nums[l];
                l++;
            }

            // snapshot length
            if (sum >= target) {
                minLength = min(minLength, r - l + 1);
            }
        }

        if (minLength == INT_MAX) { return 0; }
        return minLength;
    }
};