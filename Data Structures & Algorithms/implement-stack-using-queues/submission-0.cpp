class MyStack {
private:
    struct Node {
        shared_ptr<Node> next;
        int val;

        Node(int v, shared_ptr<Node> n) : val(v), next(n) {}
    };

    shared_ptr<Node> q;

public:
    MyStack() {
        ;
    }
    
    void push(int x) {
        q = make_shared<Node>(x, q);
    }
    
    int pop() {
        if (!q) return -1;
        
        int val = q->val;
        q = q->next;
        return val;
    }
    
    int top() {
        if (!q) return -1;
        return q->val;
    }
    
    bool empty() {
        return (q == nullptr);
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */