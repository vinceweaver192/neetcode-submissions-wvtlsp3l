class StockSpanner {
private:
    vector<pair<int,int>> st; // span, price

public:
    StockSpanner() {
        ;
    }
    
    int next(int price) {
        int span = 1;
        while (!st.empty() && price >= st.back().second) {
            span += st.back().first;
            st.pop_back();
        }
        st.push_back({span, price});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */