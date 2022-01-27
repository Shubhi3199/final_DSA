// Time - o(N) and Space - O(K)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // we use a deque as we want to build a monotonic decreasing queue, we'll remove elements from the backside of the array everytime we get a new element to be inserted in the window and also we'll have to reomve elemnets from the front as we move our sliding window by 1 step
        vector<int> res;
        for (int idx = 0; idx < nums.size(); idx++) {
            if (dq.empty() == false and dq.front() <= idx - k) {
                // i.e. the index at the front of the array is not inside the current sliding window, so it has to be removed from the front of the dq
                dq.pop_front();
            }
            while (dq.empty() == false and nums[dq.back()] <= nums[idx]) {
                // as all the elements present in the window which are smaller than the current element are never gonna be the max ele in any window from now on as we already have an ele at index = idx which is greater than them and that to at their left, so we can remove all those elements
                dq.pop_back();
            }
            dq.push_back(idx);
            if (idx >= k-1) {
                // i.e. we have atleast 1 window ready
                res.push_back(nums[dq.front()]);
            }
        }
        return res;
    }
};
