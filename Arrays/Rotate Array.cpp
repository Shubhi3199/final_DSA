// https://leetcode.com/problems/rotate-array/
class Solution {
public:
    void reverse(vector<int> &nums) {
        int start = 0, end = nums.size()-1;
        while (start < end) {
            swap(nums[start], nums[end]);
            start++; end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        reverse(nums);
        k = k % nums.size();
        int start = 0, end = k-1;
        while (start < end) {
            swap(nums[start], nums[end]);
            start++; end--;
        }
        start = k, end = nums.size()-1;
        while (start < end) {
            swap(nums[start], nums[end]);
            start++; end--;
        }
    }
};
