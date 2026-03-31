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

        // To actually return the value/s of the duplicates, can create
        // another set dedicated to
        //
        
        /*
        // Practice of looping vector

        for (int i: nums)
            std::cout << i << ' ';

        for (auto itr = nums.begin(); itr != nums.end(); itr++){
            std::cout << *itr << ' ';
        }
        */

        //std::cout << nums[0] << ' ';
        //for (auto itr = numSet.begin(); itr != numSet.end(); itr++){}
        return false;
    }
};
