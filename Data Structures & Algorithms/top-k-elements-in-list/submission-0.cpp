class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // TODO:
        // - use hashmap
        // - count all occurrences of every val in nums
        //
        // - use 2D array
        // - using the hashmap, use the occurences count => indices 
        //   o then use the actual key nums and add those values to the array at that count
        // 
        // Ex. nums = [1,1,1,2,2,0,0,3], k = 2
        // arr[duplicates #][key] =>  : arr[1] = [3], arr[2] = [2,0], arr[3] = [1]

        unordered_map<int,int> count; // key, counts

        for (auto n : nums) {
            count[n] += 1;
        }

        // 2D array for ordering least occurring to most occuring index [0 - nums.size() + 1]
        vector<vector<int>> freq(nums.size()+1);

        // iterate over hashmap
        for (auto pair : count) {
            freq[pair.second].push_back(pair.first); // add the key to the back of that nums count
        }

        // now iterate backwards to get the last k items
        vector<int> result;

        for (int i = freq.size() - 1; i > 0; i--) {
            // iterate over every val arr at each index
            for (int n : freq[i]) {
                // add to result list
                result.push_back(n);

                // check size of result list to being == k
                if (result.size() == k) {
                    return result;
                }
            }
        }
        return result;
    }
};
