class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // ToDo: (2 Pointer Approach: Left & Right)
        // *** General Rules ***
        //  - To get max value, MUST buy at lowest price before prices start increasing
        //      o Only need to start checking once price stops decresing
        //  - The nature of moving along to the right means that since the left value will
        //    always be the current smallest value
        //      o Subsequently, this means that the right value has to always be greater than
        //        than the left value, but will continue progressing until the highest value
        //        is achieved
        //
        // 1. Loop through entire vector of prices (While loop)
        //   - base case is the 'sell' variable 
        // 2. Create 2 variables (left and right or buy and sell)
        //   - continue to move left variable along until values start increasing
        // 3. Calculate the difference of the buy and sell price (left - right) and
        //    store that value as the profit
        // 4. Compare that profit with the maxProfit using 'maxProfit = max(profit, maxProfit)'
        // 5. After loop has terminated, return the value of maxProfit

        int maxProfit = 0;
        int profit = 0;
        int buy = 0;  // left index starting at first value
        int sell = 1; // right index starting at the next value

        while (sell < prices.size()) { // vectors use size
            // start by checking current values of left and right (buy and sell)
            if (prices[buy] < prices[sell]){
                // if true, then calc profit
                profit = prices[sell] - prices[buy];

                // keep track of max profit
                maxProfit = max(profit, maxProfit);
            }
            else {
                // if prices are the same or keep decresing, then move buy index to the right
                buy = sell;
            }

            // increment sell index to find the highest sell value
            sell++;
        }

        // return the result of maxProfit
        return maxProfit;
    }
};
