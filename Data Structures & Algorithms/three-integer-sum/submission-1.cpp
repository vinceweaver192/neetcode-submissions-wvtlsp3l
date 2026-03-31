class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 1. start by sorting nums
        sort(nums.begin(), nums.end());

        // store results
        vector<vector<int>> results;

        // 2. now iterate to all nums indices
        for (int i = 0; i < nums.size(); i++) {
            // since list is sorted:
            // 1. if the current val at index i is positive (all values after will be positive & result can never be 0)
            if (nums[i] > 0) {
                // use 'break' to end the looping entirely
                break;
            }
            // 2. duplicate constraint from question, MUST NOT contain duplicates
            //    - make sure index is NOT the starting index (we want to check the prev)
            if (i > 0 && nums[i] == nums[i-1]){
                // use 'continue' to skip to the next iteration in the loop
                continue;
            }

            // at this point, index val can be good, proceed with checking if match exist == 0

            // initialize 2 pointer solution: left, right
            int l = i + 1;
            int r = nums.size() - 1;

            // loop until left meets right
            while (l < r) {
                // calculate the sum of all 3 values at each index
                int sum = nums[i] + nums[l] + nums[r];

                // check if sum is 0
                if (sum == 0) {
                    // append all items into results array and increment BOTH pointers
                    results.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    // *** HUGE Gotcha Here ***
                    //     - While at the same starting index 'i', the values for left and right
                    //     - so while we check that the 'i' values are unique, we must also check for 
                    //       unique left and right pointer values

                    // Only need to check left pointer
                    // - loop until:
                    //   1. left pointer isnt a duplicate of prev left ptr
                    //   2. l < r
                    while (l < r && nums[l] == nums[l-1]) {
                        l++;
                    }
                }
                else if (sum < 0) {
                    // increment left by 1
                    l++;
                }
                else {
                    // sum > 0
                    r--;
                }
            }
        }

        return results;
    }
};
