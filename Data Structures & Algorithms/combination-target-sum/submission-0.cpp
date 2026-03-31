class Solution {
public:

    // global result solution var
    vector<vector<int>> result;

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        // use backtracking and dfs to pop_back
        // Goal:
        // - populate a list that leads to a solution
        // - for each recursive function call, the call stack will grow until a solution is reached
        //   o if no solution is reached, the array will pop_back all of its recursive calls and 
        //     remove that list from memory
        // - if a solution is found, add that list to the 2D solution list and return
        // - MUST sort nums prior to dfs
        sort(nums.begin(), nums.end());
        
        // call dfs
        // - starting index (iterate over every int in nums)
        // - 1D curr array for possible solutions
        // - total current sum
        // - nums array
        // - original target
        dfs(0, {}, nums, target);

        return result;
    }

    // dfs
    void dfs(int i, vector<int> curArr, vector<int>& nums, int target) {
        // base case
        if (target == 0) {
            // append to result
            result.push_back(curArr);
            // return
            return;
        }
        // boundary case
        if (i >= nums.size() || target < 0) {
            return;
        }

        // append current val
        curArr.push_back(nums[i]);

        // traverse recursively
        dfs(i, curArr, nums, target - nums[i]);

        // backtrack and pop
        curArr.pop_back();

        // traverse the other decision, dont take current (instead take i + 1)
        // purpose is to only handle skipping traversals
        dfs(i + 1, curArr, nums, target);
    }
};
