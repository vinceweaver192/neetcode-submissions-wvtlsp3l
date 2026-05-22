class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // map of all double sums, and count pairs
        unordered_map<long long, vector<int>> sumPairs;
        sort(nums.begin(), nums.end());

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                const long long sumPair = (long long)nums[i] + nums[j];
                sumPairs[sumPair].push_back(i);
                sumPairs[sumPair].push_back(j);
            }
        }

        set<vector<int>> uniqueRes;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                const long long sumPair = (long long)nums[i] + nums[j];
                const long long diff = (long long)target - sumPair;
                if (sumPairs.count(diff)) {
                    // check idxs and avoid matching idxs
                    for (int idx = 0; idx < sumPairs[diff].size(); idx += 2) {
                        const int x = sumPairs[diff][idx];
                        const int y = sumPairs[diff][idx+1];
                        if (x <= j) {
                            continue;
                        }
                        //vector<int> quad = {nums[i], nums[j], nums[x], nums[y]};
                        //sort(quad.begin(), quad.end());
                        uniqueRes.insert({nums[i], nums[j], nums[x], nums[y]});
                    }
                }
            }
        }

        return vector<vector<int>>(uniqueRes.begin(), uniqueRes.end());
    }
};