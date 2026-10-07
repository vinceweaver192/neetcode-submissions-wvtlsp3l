class Solution {
public:
    int rob(vector<int>& nums) {
        int prev1 = 0;
        int prev2 = 0;

        for (int i = 0; i < nums.size(); i++) {
            int cur = max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
        // vector<int> sums;
    
        // if(nums.size())
        // {
        //     sums.push_back(nums[0]);
        // }
    
        // for(int i = 1; i < nums.size(); i++)
        // {
        //     int temp = nums[i];
        //     if(i - 2 >= 0)
        //     {
        //         temp += sums[i - 2];
        //     }
    
        //     int next = sums[i - 1];
    
        //     if(temp > sums[i - 1])
        //     {
        //         next = temp;
        //     }
        //     sums.push_back(next);
        // }
    
        // int best = (sums.size() - 1 >= 0) ?
        //         sums[sums.size() - 1] :
        //         0;
        // return best;
    }
};