class MedianFinder {

// Solution Approach:
// 1. create a minHeap (largeVals[6,7,8,9]) and maxHeap (smallVals[5,4,3,2,1])
//    - priority queues
public:
    priority_queue<int, vector<int>, greater<int>> largeVals;
    priority_queue<int, vector<int>, less<int>> smallVals;

    MedianFinder() {
        // not necessary
        ;    
    }
    
    void addNum(int num) {
        // TODOs:
        // 1. add vals to smallVals (maxHeap) first, then begin rebalancing
        // 2. Rebalancing Rule 1: 
        //    - Every element in largeVals MUST be larger than every
        //      element in smallVals.
        //    * MUST check if heaps are empty prior to accessing *
        // 3. Rebalancing Rule 2:
        //    - if smallVals (maxHeap) is larger than largeVals (minHeap) 
        //      by 2 or more vals, then push to large, pop from small
        // 4. Rebalancing Rule 3:
        //    - if largeVals (minHeap) is larger than smallVals (maxHeap)
        //      by 2 or more vals, then push to small, pop from large

        smallVals.push(num); // Line 1.

        // Rule 1:
        if (!largeVals.empty() && largeVals.top() < smallVals.top()) {
            largeVals.push(smallVals.top());
            smallVals.pop();
        } 
        // Rule 2:
        if (smallVals.size() >= largeVals.size() + 2) {
            largeVals.push(smallVals.top());
            smallVals.pop();
        }
        // Rule 3:
        if (largeVals.size() >= smallVals.size() + 2) {
            smallVals.push(largeVals.top());
            largeVals.pop();
        }
        // *** MUST check all rules independently of one another ***
    }
    
    double findMedian() {
        // check if:
        // 1. sizes of heaps are equal => get the tops of heaps and get average
        // 2. else if minHeap size is larger, then get top of minHeap
        // 3. else, get top of max heap
        if (largeVals.size() == smallVals.size()) {
            return smallVals.top() + (largeVals.top() - smallVals.top()) / 2.0;
        }
        else if (largeVals.size() > smallVals.size()) {
            return largeVals.top();
        }
        else {
            return smallVals.top();
        }
    }
};
