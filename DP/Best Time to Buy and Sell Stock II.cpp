class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_buy = prices[0];
        int profit = 0;
        for (int price: prices) {
            if (price > min_buy) {
                // We can sell the stock 
                profit += price - min_buy;
                min_buy = price; // as we have sold the stock so the prev min_buy is not valid and we need to buy again on the same day
            }
            else min_buy = min(min_buy, price);
        }
        return profit;
    }
};
