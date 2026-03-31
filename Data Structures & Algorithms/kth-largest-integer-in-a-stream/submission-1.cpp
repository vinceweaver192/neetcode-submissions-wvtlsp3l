class KthLargest {
/*
private:
    // naive solution:
    vector<int> nums;
    int k;

public:
    // constructor's only job is to initialize private variables
    KthLargest(int k, vector<int>& nums) {
        this->nums = nums;
        this->k = k;
    }
    
    // add method TODO:
    // 1. push_back to vector
    // 2. return the k-th largest element
    //
    // Methods of Solving:
    // - sort the array, then subtract by K-th elements
    // * Since we are sorting everytime we call 'add()',
    //   the solution is dependent on the number of times
    //   we call the function 'n'
    //
    // *** Therefore ***
    //     - Average time complexity will be O(n * m log(m))
    int add(int val) {
        this->nums.push_back(val); // O(1)
        sort(this->nums.begin(), this->nums.end()); // O(n log(n))
        // return the k-th element since vector is now sorted
        // - subtract k from the size of the array
        return nums[nums.size() - k];
    }
    */
private:
    // Optimal Solution:
    // 
    // Create a priority Queue:
    //
    // - Add
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;

public:
    // Purpose:
    // - Constructor 
    //   1. do more heavy lifting in beginning by 
    //      maintaing sorted queue ascending order
    //   2. Since we only care about the k-th greatest 
    //      value, we dont need to keep all the values
    //      smaller than the k-th, meaning we can use
    //      k elements as a size to check with the priority 
    //      queue
    //
    // - TODO:
    //   1. loop through all nums and push to pq
    //   2. since we pop from the top (smallest value),
    //      we can pop the n-th smallest values as long as
    //      we maintain a size of 'k' elements in the pq
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums){
            // continuously maintains sorted queue small -> large
            pq.push(num);

            if (pq.size() > k){
                //cout << "removed values: " << pq.top() << endl;
                pq.pop();
            }
        }
        //cout << "Current top of queue: " << pq.top() << endl;
        //cout << "Current size of queue: " << pq.size() << endl;
    }

    int add(int val) {
        // add to queue first and sort k values
        pq.push(val); // O(log(k))

        // now have 1 extra value than k, need to pop
        // *** EDGE CASE ***
        // check size to be greater than k
        // before popping incase we initialize constructor 
        // with no values or fewer than k
        if (pq.size() > k){
            pq.pop();
        }

        // now top value is the k-th larget, can return top
        return pq.top();
    }
};
