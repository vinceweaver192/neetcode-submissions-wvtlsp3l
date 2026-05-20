class Solution {
private:
    vector<int> mergeTwoLists(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        int j = 0;
        vector<int> res;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                res.push_back(nums1[i]);
                i++;
            }
            else {
                res.push_back(nums2[j]);
                j++;
            }
        }
        while (i < nums1.size()) {
            res.push_back(nums1[i++]);
        }
        while (j < nums2.size()) {
            res.push_back(nums2[j++]);
        }

        return res;
    }

    vector<int> divAndConq(vector<int>& nums, int l, int r) {
        if (l >= r) {
            return {nums[l]};
        }

        int mid = l + (r - l)/2;

        auto left = divAndConq(nums, l, mid);
        auto right = divAndConq(nums, mid + 1, r);

        return mergeTwoLists(left, right);
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        return divAndConq(nums, 0, nums.size()-1);
    }
};