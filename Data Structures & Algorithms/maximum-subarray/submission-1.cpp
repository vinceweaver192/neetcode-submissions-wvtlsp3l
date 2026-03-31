class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Solution:
        // reset every negative num and take current number only, then store maxes in maxSum var

        int maxS = INT_MIN;
        int curS = 0;

        for (int num : nums) {
            if (curS < 0) {
                curS = 0;
            }
            curS += num;
            maxS = max(curS, maxS);
        }

        return maxS;
    }
};
