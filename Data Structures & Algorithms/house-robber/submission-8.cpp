class Solution {
public:
    int rob(vector<int>& nums) 
        {
        vector<int> sums;
    
        if(nums.size())
        {
            sums.push_back(nums[0]);
        }
    
        for(int i = 1; i < nums.size(); i++)
        {
            int temp = nums[i];
            if(i - 2 >= 0)
            {
                temp += sums[i - 2];
            }
    
            int next = sums[i - 1];
    
            if(temp > sums[i - 1])
            {
                next = temp;
            }
            sums.push_back(next);
        }
    
        int best = (sums.size() - 1 >= 0) ?
                sums[sums.size() - 1] :
                0;
        return best;
    }
};