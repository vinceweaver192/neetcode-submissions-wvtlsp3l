class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // Approach:
        // 1. Google - Binary Search of all numbers between 1 and max element in piles
        //    - 2 ways to calculate mid value, try both, or do simpler one
        // 2. during each binary search, calculate middle number and determine if it 
        //    is less than h 'hours'
        //    - calculation: totalTime = totalTime + (piles[i] / mid value)
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int result = r; // worst case, if Binary search fails

        // run BS
        while (l <= r) {
            // calculate mid
            int mid = (l + r) / 2;

            // store eating result time:
            long long totalTime = 0;

            // test k eating rate with mid val
            for (int pile : piles) {
                totalTime += (pile + mid - 1) / mid;
            }

            // now perform general binary search checks
            if (totalTime <= h) {
                // then good, but can check for better
                result = mid;
                r = mid - 1;
            }
            else {
                // need to check for a higher mid value
                l = mid + 1;
            }
        }

        // return result
        return result;
    }
};
