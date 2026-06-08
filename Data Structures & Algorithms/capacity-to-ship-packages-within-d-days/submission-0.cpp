class Solution {
private:
    bool canComplete(vector<int>& weights, int days, int cap) {
        int sum = 0;
        int dayCount = 1;
        for (int w : weights) {
            if (sum + w > cap) {
                dayCount++;
                sum = w;
            }
            else {
                sum += w;
            }
        }
        return dayCount <= days;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        // to set the capacity, find the min and max bounds
        int upper = 0;
        int lower = 0;
        for (int w : weights) {
            lower = max(lower, w);
            upper += w;
        }

        while (lower < upper) {
            const int mid = (upper - lower) / 2 + lower;

            if (canComplete(weights, days, mid)) {
                // check lower inclusive
                upper = mid;
            }
            else {
                lower = mid + 1;
            }
        }

        return upper;
    }
};