class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int bound = nums.size() / 3;
        unordered_map<int, int> umap;

        for (int num : nums) {
            umap[num]++;
        }

        vector<int> res;

        for (auto [num, count] : umap) {
            if (count > bound) {
                res.push_back(num);
            }
        }

        return res;
    }
};