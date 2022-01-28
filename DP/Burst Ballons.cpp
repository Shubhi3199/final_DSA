class Solution {
public:
    int maxCoins(vector<int>& nums) {
        // max_coins[i][j] => stores the max coins that can be collected by bursting ballons in the range [i to j] from the entire array
        vector<vector<int>> max_coins(nums.size(), vector<int> (nums.size()));
        for (int gap = 0; gap < nums.size(); gap++) {
            for (int start = 0; start + gap < nums.size(); start++) {
                int end = start + gap;
                // Now in the current range [start, end] we want to collect the maximum coins, so for each ballon in this range, we'll recursively ask the question that what is the max coins colleccted of the current ballon is bursted at rhe last, for ex. if we have the ballons - [ABCD], then we have 4 options :
                // 1. Delete A ballon at last so total coins => nums[A] + dp[B][D]
                // 2. Delete B ballon at last, total coins => dp[A][A] + nums[B] + dp[C][D]
                // 3. Delete C ballon at last, total coins => dp[A][B] + nums[C] + dp[D][D]
                // 4. Delete D ballon at last, total coins => dp[A][C] + num[D]
                int coins = INT_MIN;
                for (int divider = start; divider <= end; divider++) {
                    int left_coins = (divider == start ? 0 : max_coins[start][divider-1]);
                    int right_coins = (divider == end ? 0 : max_coins[divider+1][end]);
                    int cur_ballon_cost = (start == 0 ? 1 : nums[start-1]) * nums[divider] * (end >= nums.size()-1 ? 1 : nums[end+1]); // this value caomes when the current ballon is burst at the last, so the cost will be for this last ballon in the range [start to end] will be the product of nums[cur_ballon] + nums[start-1] + nums[end+1] 
                    int total_coins = left_coins + right_coins + cur_ballon_cost;
                    coins = max(coins, total_coins);
                }
                max_coins[start][end] = coins;
            }
        }
        return max_coins[0][nums.size()-1]; // max coins collected on bursting ballos from 9o to n-1] 
    }
};
