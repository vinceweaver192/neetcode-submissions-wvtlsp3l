class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(); 
        int size = n + 1; // size for actual arr
        int sum = 0;

        for (int i = 0; i < size; i++) {
            sum += i;
        }

        for (int num : nums) {
            sum -= num;
        }

        return sum;
    }
};
