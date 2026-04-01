class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // ensure intervals are in sorted order first by starting times
        // append all merged intervals into a new array
        // create an interval and set its values to the most expansive of the current and prior
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;

        int l = 0, r = 0;
        int size = intervals.size();

        while (l < size) {
            // create one interval
            vector<int> interval;

            int startTime = intervals[l][0];
            int endTime = intervals[l][1];
            interval.push_back(startTime);
            interval.push_back(endTime);

            // check if interval can be merged with others
            r++;
            while (r < size && interval[1] >= intervals[r][0]) {
                // update end time with the greater of the 2
                interval[1] = max(interval[1], intervals[r][1]);
                r++;
            }
            // maximized interval range, just need to add
            res.push_back(interval);

            // set l = r to get the next interval
            l = r;
        }

        return res;
    }
};
