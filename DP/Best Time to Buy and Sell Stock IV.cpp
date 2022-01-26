class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int num_days = prices.size();
        // max_profit[i][j] => the max amount of profit generated after performing i number of trqansactions till the jth day 
        if (num_days == 0) return 0;
        vector<vector<int>> max_profit(k+1, vector<int> (num_days));
        // Base case - 1
        for (int day = 0; day < num_days; day++) {
            max_profit[0][day] = 0; // if we are doing 0 transaction then till any possible day, we'll have 0 profit
        }
        // Base case - 2
        for (int num_transactions = 0; num_transactions < k; num_transactions++) {
            max_profit[num_transactions][0] = 0; // if we do any number of transactions on the 1st day itself then the max profit that we'll generate will be atmax 0 as we would have to buy and sell at the same day itself at the same price, so no profit generated
        }
        for (int num_trans = 1; num_trans <= k; num_trans++) {
            for (int cur_day = 1; cur_day < num_days; cur_day++) {
                // Now the max_profit[num_trans][cur_day] depends on 2 major things:
                // 1. On max_profit[num_trans][cur_day-1], that is we have already done the give number of transactions (num_trans) on the previous day (cur_day-1)
                // Vs
                // 2. On max_profit[num_trans-1][day-1] Vs max_profit[num_trans-1][day-2] Vs max_profit[num_trans-1][day-3] Vs max_profit[num_trans-1][day-4]....., becauase when we have done 1 lesser transaction on any of the prev days then we can perform the last transaction on the cur_day (where we sell at the cur_day and would have bought on the best_buy_day)
                max_profit[num_trans][cur_day] = max_profit[num_trans][cur_day-1];
                for (int best_buy_day = 0; best_buy_day < cur_day; best_buy_day++) {
                    max_profit[num_trans][cur_day] = max(max_profit[num_trans][cur_day], max_profit[num_trans-1][best_buy_day] + prices[cur_day] - prices[best_buy_day]); // here we have added {prices[cur_day] - prices[best_buy_day]},  to the max_profit till the best_buy_dy with 1 lesser trasaction as we perform the last transaction on the cur_day
                }
            }
        }
        return max_profit[k][num_days-1];
    }
};
