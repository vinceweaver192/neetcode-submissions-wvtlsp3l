class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // deque solution
        //
        // TODO:
        // 1. maintain deque in descending order (ex. 5,4,3,2,1)
        // 2. to maintain O(n) time, we only care to add values to the deque
        //    if they are less than the current max value in k
        // 3. when adding values to deque:
        //    - when adding new max value, remove (pop) all values from the right (or back)
        //      and when deque is empty, add the new max to the left
        //    - when adding all other values (lower than max), simply just remove all
        //      values that are less than the current value from the right and add the 
        //      current value when the condition for top of deque (or back since from right)
        //      is greater than current value (ex. while (deque.back() < nums[i]) -> keep popping
        //      from back OR until deque is empty)
        // 4. use l and r for left and right pointers to keep track of the boundary indices 
        //    of k (ex. l = 0, r = k-1... l++ and r++... -> while (r < nums.size()) )

        // better to store indices and just nums[dq[0]] to represent max
        deque<int> dq; // queue of indices
        vector<int> max;

        int l = 0;

        // if we start right at 0, we can traverse the beginning k
        //int r = k-1;
        int r = 0;

        while (r < nums.size()){
            // remove all min values to deque
            // deque only store indices of the highest values in nums[] in descending order:
            // Ex. deque = [1,3,4], nums[deque.back() == 4] = 8
            //     - nums[1] = 10, nums[3] = 9
            while ((!dq.empty() && nums[dq.back()] < nums[r])){
                dq.pop_back();
            }

            // can now add right value to deque
            // since at this point, nums[r] is either equal to, or the next greatest value
            // OR
            // deque is empty
            dq.push_back(r);

            // check the left pointer and move it along if it's index is larger
            // than the highest values index (which is the front of the deque)
            if (l > dq.front()){
                dq.pop_front();
            }

            // once r has reached the size of k, can now store max value of window k
            // (nums[dq.front()]) into the max vector
            if (r >= k-1){
                // add current front of deque to output
                max.push_back(nums[dq.front()]);

                // can now increment l and perform complete window shifts
                l++;
            }

            // traverse r for every iteration
            r++;
        }
        return max;
    }
};
