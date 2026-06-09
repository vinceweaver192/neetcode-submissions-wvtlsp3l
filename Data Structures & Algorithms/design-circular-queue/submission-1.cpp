class MyCircularQueue {
private:
    queue<int> buffer;
    int back;
    int capacity;

public:
    MyCircularQueue(int k) {
        capacity = k;
        back = -1;
    }
    
    bool enQueue(int value) {
        if (!isFull()) {
            buffer.push(value);
            back = value;
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        if (!isEmpty()) {
            buffer.pop();
            if (isEmpty()) {
                back = -1;
            }
            return true;
        }
        return false;
    }
    
    int Front() {
        if (!isEmpty()) {
            return buffer.front();
        }
        return -1;
    }
    
    int Rear() {
        return back;
    }
    
    bool isEmpty() {
        if (buffer.size() == 0) {
            return true;
        }
        return false;
    }
    
    bool isFull() {
        if (buffer.size() == capacity) {
            return true;
        }
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */