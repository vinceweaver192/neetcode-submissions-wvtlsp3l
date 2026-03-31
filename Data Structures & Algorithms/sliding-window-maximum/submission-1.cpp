class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // store results
        vector<int> results;

        // get left and right pointer: 0 to k
        int l = 0;
        int r = 0; // start r to the same position as left

        // create a deque that stores the max value to the left and
        // all smaller values are to the right of it
        // - deque or double ended queue
        // - deque will store indices 
        //   o Makes it possible to check left and right pointers
        //   o Makes it possible to check and maintain the window size parameters
        deque<int> dq; 

        while (r < nums.size()) {
            // ensure queue is correctly holding the highest value index to the front()
            // TODO:
            // 1. pop all elements from the back that are less than the current nums[r] value
            //    OR
            // 2. stop popping when queue is empty

            // *** MUST: iterate this check separately from the rest of the loop ***
            //     - use a while-loop to ensure the queue is populated correctly (iterativly)
            while (!dq.empty() && nums[dq.back()] < nums[r]) {
                // pop value from back
                dq.pop_back();
            }

            // can now push r value from the back
            dq.push_back(r);

            // 2 checks:
            // 1. check if window size == k
            //    - if window size is atleast size k
            //      o must increment left pointer to the right by 1
            //      o must add top of queue to list of results
            // 2. check if left pointer is greater than front of queue
            if (l > dq.front()) {
                // pop front
                dq.pop_front();
            }

            // now check window size
            // - once right pointer is of atleast size k-1 (as an index), then it
            //   will be of the correct window size
            // - once r index hits k-1, it will always be shifted by +1 along with
            //   left pointer and size will always stay the same
            // - check if r is >= k-1 so once it hits correct size, r will continue 
            //   to increment its index, but should still pass this check
            if (r >= k-1) {
                // window size has been reached
                
                // add max front() of queue to results
                results.push_back(nums[dq.front()]);

                // increment left pointer
                l++;
            }

            // always increment right pointer
            r++;
        }

        return results;
    }
};
