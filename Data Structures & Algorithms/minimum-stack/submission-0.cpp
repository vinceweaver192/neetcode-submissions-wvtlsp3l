class MinStack {
private:
    // use 2 stacks
    // 1. stack for holding all normally added values
    // 2. stack for holding only min values
    stack<int> st;
    stack<int> minStack;

public:
    MinStack() {
        ; // not necessary
    }
    
    void push(int val) {
        st.push(val);
        val = min(val, !minStack.empty() ? minStack.top() : INT_MAX);
        minStack.push(val);
    }
    
    void pop() {
        st.pop();
        minStack.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
