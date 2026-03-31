class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // TODO:
        // 1. create a stack to store areas that extent to other heights
        //    - must compare current height with previous heights from stack
        //    - must remove values from stack when the current value is shorter
        //      o Still need to calculate height of top of stack that corresponds
        // store max area result:
        int maxArea = 0;

        // create a stack to store the index, height pairs
        stack<pair<int,int>> stack;

        // iterate through the list of heights
        for (int i = 0; i < heights.size(); i++) {
            // 1. save the starting index to be used later if the heights continue to increase
            // 2. if the current height is larger than the height at top of stack:
            //    - loop through the stack 
            //    - calculate maxArea and store results
            //    - remove top of stack, but update the starting index to the current index
            // 3. after stack loop check, push starting index and current height to top of stack
            //    - this is the default action for when current height is shorter than top of stack

            int start = i;

            // check if the top of stack is bigger than the current value
            //
            // Reasoning:
            // - as soon as the height begins to decrease, we want to remove that value
            //   from the stack
            // - before we remove from the stack, we want to calculate what the maxArea
            //   of the current top of stack since it could be the largest, but also bc
            //   it is no longer necessary for calculating future areas
            while (!stack.empty() && stack.top().second > heights[i]) {
                pair<int,int> top = stack.top();
                // extract variables from pair
                int idx = top.first;
                int height = top.second;

                // since 'i' is the bigger index and we want a positive multiplier value,
                // subtract it from the index 'idx' stored in the top of stack to get
                // the boundaries for how big this part of the maxArea should be.
                maxArea = max(maxArea, height * (i - idx));

                // dont forget to update the start index
                start = idx;
                stack.pop();
            }
            stack.push({start,heights[i]});
        }

        // iterate through the remaining stack
        while (!stack.empty()) {
            // get top and pop
            // extract top:
            int idx = stack.top().first;
            int height = stack.top().second;
            int n = heights.size();

            maxArea = max(maxArea, height * (n-idx));

            stack.pop();
        }
        // if a random value is returned, then the return value is missing
        return maxArea;
    }
};
