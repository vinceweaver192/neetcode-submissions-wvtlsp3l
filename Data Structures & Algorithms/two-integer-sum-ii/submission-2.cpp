class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // 2 pointer solution
        // - if current sum is greater, traverse right backwards
        // - if current sum is less, traverse left forward
        int curSum = 0;

        int l = 0;
        int r = numbers.size() - 1;

        while (l < r) {
            if (numbers[l] + numbers[r] == target) {
                return {l+1, r+1};
            }
            if (numbers[l] + numbers[r] > target) {
                r--;
            }
            else { // sum < target
                l++;
            }
        }

        return {};
    }
};
