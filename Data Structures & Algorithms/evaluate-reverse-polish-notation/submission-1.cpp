class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // Stack Solution:
        // 1. traverse the vector of tokens
        // 2. append all numbers to stack
        // 3. once a operand is reached, perform the calculation
        //    - use the stack to grab the current top and pop the top
        //    - perform calculation with previous top and new top and pop again
        // 4. add the result of the calculation back into the stack
        // 5. return top of stack
        stack<int> st;

        // loop
        for (const string& t : tokens) {
            if (t == "+") {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                st.push(a + b);
            }
            else if (t == "-") {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                st.push(b - a); // for subtract, must be swapped (b MINUS a)
            }
            else if (t == "*") {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                st.push(a * b);
            }
            else if (t == "/") {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                st.push(b / a); // for divide, must be swapped (b DIVIDED BY a)
            }
            else {
                // at this point, t is a number and must be converted
                st.push(stoi(t));
            }
        }
        return st.top();
    }
};
