class Solution {
public:
    bool can_partition(int cur_idx, int cur_sum, int &target_sum, int k, vector<bool> &visited, vector<int> &nums) {
        if (cur_sum == target_sum) {
            // i.e. we have found 1 valid subset
            if (k == 1) {
                // i.e. we have already found k-1 valid subsets and only 1 valid subset is to be found next, we can return true as the remaining ele will definately form sum == traget_sum as we have already verified that total % k == 0
                return true;
            }
            // but if k != 1, so we'll recursively try to found the rest of the valid subsets in the remaining elements by iterating on the array again from 0 index and only choosing thise ele which are not yet visited
            return can_partition(0, 0, target_sum, k-1, visited, nums);
        }
        // Now here we try to check if the cur ele can be a part of the cur subset or not, thus we recursively try each ele and backtrack to find other possiblities
        for (int start = cur_idx; start < nums.size(); start++) {
            if (visited[start] == true) continue;
            if (cur_sum + nums[start] <= target_sum) {
                // so the cur ele can be a part of the cur subset
                visited[start] = true;
                cur_sum += nums[start];
                bool are_subsets_possible = can_partition(start + 1, cur_sum, target_sum, k, visited, nums);
                if (are_subsets_possible == true) return true; // is found k valid subsets then no need to check further, simply return true;
                // else backtrack and explore more options
                visited[start] = false;
                cur_sum -= nums[start];
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if (k == 0) return false;
        if (k == 1) return true; // the entire array is the ans for k = 1
        if (k > nums.size()) return false; // we cannot do more than n partitions of an array of sie n
        int total = 0;
        for (int num: nums) {
            total += num;
        }
        if (total % k != 0) return false;
        int subset_sum = total / k; // sum of each subset if it's possible to do k partitions
        int n = nums.size();
        vector<bool> visited(n, false); // Used to check what all nums are already included in a subset so that we don't reconsider it in another subset
        return can_partition(0, 0, subset_sum, k, visited, nums);
    }
};
