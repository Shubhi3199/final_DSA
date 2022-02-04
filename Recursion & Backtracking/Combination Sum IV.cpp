class Solution {
public:
    int count_ways(int target, vector<int> &nums, vector<int> &dp) {
        if (target == 0) return 1;
        if (dp[target] != -1) return dp[target];
        int num_ways = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (target < nums[i]) continue;
            num_ways += count_ways(target - nums[i], nums, dp);
        }
        return dp[target] = num_ways;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        return count_ways(target, nums, dp);
    }
};
