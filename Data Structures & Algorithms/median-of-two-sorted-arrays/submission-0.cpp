class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // create 2 referenced vectors for nums1 and nums2
        vector<int> & A = nums1;
        vector<int> & B = nums2;

        // calc total size of both arrays if they were combined
        int size = A.size() + B.size();

        // calculate the halfway point to know how to split the left and right paritions
        int half = (size + 1) / 2; // round up half

        // ensure that A is the smaller of the 2 lists
        if (A.size() > B.size()) {
            swap(A, B);
        }

        // assign left and right pointers for the array A
        int l = 0;
        int r = A.size();

        // binary search while loop
        while (l <= r) {
            // get the partitioned index for A
            int i = (l + r) / 2;

            // i will always be less than 'half' var, so the difference of half and i will be 
            // the partition for B
            int j = (half - i);

            // edge case handling for cases where we either use all of partition A or all of partition B
            // - make Aleft a conditional assignment, 
            //  Ex. if 'i' is > 0, then proceed with normal assignment of Aleft = A[i-1],
            //      if 'i' is 0 (first value), then assign i to min int value
            int Aleft = i > 0 ? A[i-1] : INT_MIN;
            // do the same for Aright, Bleft, and Bright since in either cases, we should be able to take
            // all of one list's partition if necessary
            int Aright = i < A.size() ? A[i] : INT_MAX;

            // use j for this partition
            int Bleft = j > 0 ? B[j-1] : INT_MIN;
            int Bright = j < B.size() ? B[j] : INT_MAX;

            // now check left and right partitions
            // 1. check if Aleft is <= Bright (if so, then this part of the partition is correct)
            // 2. check if Aright is >= Bleft (if both are true, then partition is correct)
            if (Aleft <= Bright && Aright >= Bleft) {
                // now check if the total number of elements is even or odd
                if (size % 2) {
                    // true, so it is odd
                    // return the max of the left partition
                    return max(Aleft, Bleft);
                }
                else {
                    // false, result is even
                    // return the average (min/max) of the left and right partitions
                    // max of lefts, min of rights
                    return (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0; // result has to be a double
                }
            }
            // if Aleft > Bright, move partition index 'i' to the left
            else if (Aleft > Bright) {
                // modify binary search to search left
                r = i - 1;
            }
            // Aright < Bright, move partition index 'i' to the right
            else {
                // modify binary search to search right
                l = i + 1;
            }
        }

        // if gets here and hasnt returned, return null -1
        return -1;
    }
};
