class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // return a vector {}
        //
        // Since we want to return the indices of the values in vector nums that
        // add when added together equal target, we will create a unordered map
        // to store indices and values.
        // 
        // A good way of going about this is to:
        // 1. loop through the entire array nums
        // 2. check the current index value and see if the other value exist in the list of keys
        //   - Must take the difference of the target and current value to find missing value
        // 3. If missing value exist, then return the index of the first value followed by the current index
        //   - values must be returned as a vector of 2 indices
        //   - if not found, add current value to the map using (.insert(key, value))

        unordered_map<int, int> umap; // value : index
        int val2 = -1;

        for (int i = 0; i < nums.size(); i++){
            // calculate missing value
            val2 = target - nums[i];

            // search for missing val in map
            if (umap.find(val2) != umap.end()){
                //cout << "found" << endl;
                return {umap[val2], i};
            } 
            /*
            else {
                cout << "not found" << endl;
            }
            */
            // insert pair using {}
            umap.insert({nums[i], i});
        }
        return {};
    }
};
