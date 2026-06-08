class FreqStack {
private:
    // 2D vector, [freq, pos in stack]
    vector<vector<int>> freqStack; // 0 - n-1 freq 0 indexed
    unordered_map<int,int> umap; // val : freq
    int maxFreq; // also serves as the freqStack size

public:
    FreqStack() {
        maxFreq = 0;
    }
    
    void push(int val) {
        int freq = 1;
        if (!umap.count(val)) {
            umap[val] = freq;
        }
        else {
            freq = ++umap[val];
        }
        maxFreq = max(maxFreq, freq);
        
        if (freqStack.size() < freq) {
            freqStack.push_back({val}); // push new val to new column freq
        }
        else {
            freqStack[freq-1].push_back(val); // insert 0s indexed values into their correct stack column position
        }
    }
    
    int pop() {
        int val = freqStack[maxFreq-1].back();
        freqStack[maxFreq-1].pop_back();
        umap[val]--;
        if (freqStack[maxFreq-1].empty()) {
            maxFreq--;
        }
        
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */