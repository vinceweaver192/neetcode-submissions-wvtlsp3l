class MedianFinder {
public:
    // Approach:
    // 1. Two heaps (priority queues (small vals and large vals))
    // 2. Small heap is max() and large heap is min() 
    //    - together form median
    // 3. Heap sizes should have a difference no greater than 1
    priority_queue<int, vector<int>, less<int>> smallHeap; // descending order
    priority_queue<int, vector<int>, greater<int>> largeHeap; // ascending order
    
    
    MedianFinder() {
        // not necessary
    }
    
    // Balance the num after adding it
    void addNum(int num) {
        // first push num to small heap
        smallHeap.push(num);

        // begin balancing process:
        // 1. Every element in small[] <= large[]
        if (!largeHeap.empty() && 
        smallHeap.top() > largeHeap.top()) { // if true, rebalance
            // small top (max) > large top (min)
            // add to largeHeap
            largeHeap.push(smallHeap.top());
            // pop large value that was added
            smallHeap.pop();
        }
        // 2. check if small heap size has a difference of 2 or more than large
        if (smallHeap.size() >= largeHeap.size() + 2){
            // small is too big, rebalance
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }
        // 3. opposite of last size check
        if (largeHeap.size() >= smallHeap.size() + 2){
            // large is too big, grab its min val
            smallHeap.push(largeHeap.top());
            largeHeap.pop();
        }
    }
    
    double findMedian() {
        // check if sizes are equal (then we have an even number),
        // and need to get average of 2 middle
        if (largeHeap.size() == smallHeap.size()){
            return smallHeap.top() + (largeHeap.top() - smallHeap.top()) / 2.0;
        }
        else if (smallHeap.size() > largeHeap.size()){
            return smallHeap.top();
        }
        else {
            return largeHeap.top();
        }
    }
};
