class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // create a variable to store the max val
        int maxArea = 0;

        // create stack to store the pair<index of rect, height of rect
        stack<pair<int,int>> stack; // (index : height)

        // iterate through all heights:
        for (int i = 0; i < heights.size(); i++) {
            // track the starting variable of current index height
            int start = i;

            // Loop and check:
            // 1. while stack is not empty
            // 2. while current height is larger than height in top of stack (previous height)
            while (!stack.empty() && stack.top().second > heights[i]) {
                // at this point current height is higher

                // get top element of stack
                pair<int,int> top = stack.top();
                // extract variables from pair
                int index = top.first;
                int height = top.second;

                // now calculate and pop the top of the stack to calculate the area of 
                // the prev peak height.
                // - the prev peak height is shorter than the current height, therefore, it
                //   can perfectly fit to be extended to the current height
                maxArea = max(maxArea, height * (i - index)); // current 'i' is the higher val and 
                                                              // 'index' is storing the prev index height, together they can be 
                                                              // used the find the difference for how big the area for the current
                                                              // maxArea should be
                // update start index to the top of the stack and pop the top
                start = index;
                stack.pop();
            }

            // add start to the stack to keep track of the the inclusive index
            // necessary for the multiplication line above: 
            //  - maxArea = max(maxArea, height * (i - index));
            stack.push({start, heights[i]});
        }

        // at this point, the stack will still be populated with values that have areas that reach the end
        // * its important to know that the stack will always have atleast one value left

        // loop until stack is empty
        while (!stack.empty()) {
            // extract values from top()
            int index = stack.top().first;
            int height = stack.top().second;
            int n = heights.size(); // heights.size() isnt a clean int, so must either create a var 'n' or cast int()

            // calculate the maxArea 
            // since the size spans across the entire stack:
            // 1. use the start index val from the top of each item in the stack thats used to remember the heights it is valid for
            // 2. subtract that start index from the entire size of heights[] (dont use size-1 since we want to be inclusive of current val)
            // 3. multiply that difference to the height value stored at the top of that stack start index
            maxArea = max(maxArea, height * (int(heights.size()) - index));

            // remove top of stack
            stack.pop();
        }

        // return maxArea
        return maxArea;
    }
};
