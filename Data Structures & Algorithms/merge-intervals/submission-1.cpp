class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Better Solution:
        // still sort but,
        // Use a single loop and rely on result array for tracking/updating inputs

        // 2 Options:
        // 1. if result array is empty OR interval doesnt overlap, add the current interval to result
        // 2. else if result is not empty, always check the back and check if the current interval overlaps

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;

        // for loop with 2 cases:
        for (int i = 0; i < intervals.size(); i++) {
            if (result.empty() || result.back()[1] < intervals[i][0]) { // last end time < new start time
                result.push_back(intervals[i]);
            }
            else {
                result.back()[1] = max(result.back()[1], intervals[i][1]); // update last end time
            }
        }

        return result;
    }   
};
