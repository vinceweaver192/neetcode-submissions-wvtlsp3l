class Solution {
public:
    int maxProfit(vector<int>& prices) {
        stack<int> buyIdxs;
        int profit = 0;

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i-1]) {
                buyIdxs.push(i-1);
            }
        }

        int idx = prices.size()-1;
        while (!buyIdxs.empty()) {
            int maxVal = 0;

            while (buyIdxs.top() < idx) {
                maxVal = max(prices[idx] - prices[buyIdxs.top()], maxVal);
                idx--;
            }
            profit += maxVal;
            buyIdxs.pop();
        }

        return profit;
    }
};