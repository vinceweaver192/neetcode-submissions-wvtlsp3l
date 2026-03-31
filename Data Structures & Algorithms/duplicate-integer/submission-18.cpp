class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // An unordered set is a hash of every element in the array.
        //
        // If there are duplicates in the array, then the size of 
        // the set will be smaller than the size of the array
        unordered_set<int> numSet(nums.begin(), nums.end());

        if (numSet.size() < nums.size()){
            return true;
        }

        return false;
    }
};
