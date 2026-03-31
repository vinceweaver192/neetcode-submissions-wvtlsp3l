class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // create 2 pointers
        int l = 0;
        int r = numbers.size() - 1;

        // loop until left meets right
        while (l < r) {
            // calculate sum
            int sum = numbers[l] + numbers[r];

            // check if sum is equal to target
            if (sum == target) {
                return {l + 1, r + 1}; // indices start at 1, not 0
            }
            else if (sum > target) {
                // decrement right pointer
                r--;
            }
            else {
                // sum < target
                // so increment left pointer
                l++;
            }
        }
        // if result not found, return empty vector
        return {};
    }
};
