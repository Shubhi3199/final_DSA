// The thing is that after any number of transactions, we can have atmost 2 states on a given day, either have 1 extra share bought, i.e. like B, BSB, BSBSB, BSBSBSB ..
// or be in a cleared state, where you have equal buys and sell, i.e. BS, BSBS ..

// Now the final ans will always come from the cleared off state 
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int prev_bought_price = -prices[0], prev_sold_price = 0;
        for (int i = 1; i < prices.size(); i++) {
            // 2 choices - Either to cintinue on with the prev bought state and do not do anything or come from prev_sold state and buy a new stock today
            int cur_bought_price = max(prev_bought_price, prev_sold_price - prices[i]);
            int cur_sold_price = max(prev_sold_price, prev_bought_price + prices[i] - fee);
            
            prev_bought_price = cur_bought_price;
            prev_sold_price = cur_sold_price;
        }
        return prev_sold_price;
    }
};
