class Solution {
public:
    void get_all_subsets(int idx, int target, vector<int> &cur_subset, vector<int> &nums, vector<vector<int>> &all_subsets) {
        if (target == 0) {
            all_subsets.push_back(cur_subset);
            return; // as if further go down the recurssion, we'll get -ve target
        }
        for (int cur = idx; cur < nums.size(); ) {
            if (target < nums[cur]) return; // as all the elemnets from here on to the right are definitely greater the target, so no point
            target -= nums[cur];
            cur_subset.push_back(nums[cur]);
            get_all_subsets(cur + 1, target, cur_subset, nums, all_subsets);
            // backtracking
            target += nums[cur]; // as we want to generate all the possible subsets
            cur_subset.pop_back(); // as we have come out of this call
            int prev = nums[cur];
            while (cur < nums.size() and nums[cur] == prev) cur++; // so that we don't consider same subsets, A.T.Q in [1,2,2,2,5], 5 => [1,2,2] should appear only once, so after we are done inserting the cur num in he subset then while backtracking to other possible nums, we skip all the nums which are equal to the lastly inserted num
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end()); // It's done so that while in recursion when the target_sum becomes lesser than the cur ele we are at, then we can return and not go any further down the recursion as all the number to he right of the cur number are gonna be greater than it, so no point (It's just an optimization)
        
        vector<vector<int>> all_subsets;
        vector<int> cur_subset;
        get_all_subsets(0, target, cur_subset, nums, all_subsets);
        return all_subsets;
    }
};
