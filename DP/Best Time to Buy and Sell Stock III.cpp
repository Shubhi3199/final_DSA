class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = INT_MIN;
        int n = prices.size();
        // max_selling_profit[i] => the maximum profit we could get if we sell the stock on or before the ith day
        vector<int> max_selling_profit(n); // 
        int min_stock_price = prices[0]; // to store the min price of stock till the ith day
        max_selling_profit[0] = 0; // if we want to sell the stock on the oth day then i would have bought it on the oth day itself
        for (int day = 1; day < n; day++){
            max_selling_profit[day] = max(max_selling_profit[day-1], prices[day] - min_stock_price); // Today's max selling profit could be either maximum selling price before this day or due to profit obtained on the ith day (this day)
            min_stock_price = min(min_stock_price, prices[day]);
        }
        // max_buying_profit[i] => the maximum profit that we can get when we have to buy the stock on after the ith day
        vector<int> max_buying_profit(n);
        int max_stock_price = prices[n-1]; // to store the max price of the stock so that when we buy the stock on the ith day, we know what's the max profit we can get afterwards
        for (int day = n-2; day >= 0; day--){
            max_buying_profit[day] = max(max_buying_profit[day+1], max_stock_price - prices[day]);
            max_stock_price = max(max_stock_price, prices[day]);
        }
        for (int day = 0; day < n; day++){
            max_profit = max(max_profit, max_selling_profit[day] + max_buying_profit[day]);
        }
        return max_profit;
    }
};
