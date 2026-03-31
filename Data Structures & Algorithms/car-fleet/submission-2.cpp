class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // Approach:
        // 1. store pairs of position and speed into a vector
        // 2. sort vector in reverse order
        //    - reverse starting from highest position (the cars in the front will dictate the cars that come after it)
        // 3. create and push to a stack the calculated speed it will take the cars to reach the target
        //    - equation: (casting double) (target - position) / speed => push value into stack (starting with highest position)
        //    - for popping: if stack is not empty then check top of stack
        //      o if top of stack is less than or equal to current value, dont add new val
        //      o otherwise, add val to stack
        vector<pair<int,int>> cars;

        for (int i = 0; i < position.size(); i++) {
            cars.push_back({position[i],speed[i]});
        }

        // now reverse list
        sort(cars.rbegin(), cars.rend());

        // now loop through pairs and add/pop from stack
        stack<double> st;

        for (auto& pair : cars) {
            // get new val
            double val = (double)(target - pair.first) / pair.second;

            if (!st.empty() && val <= st.top()) {
                ;
            }
            else {
                st.push(val);
            }
        }

        // return stack size for number of fleets
        return st.size();
    }
};
