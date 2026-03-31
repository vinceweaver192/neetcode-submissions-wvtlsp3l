class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // sliding window solution

        // keep track of highest sum
        // if the cur sum ever drops to negative, replace cur sum with new cur val

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
