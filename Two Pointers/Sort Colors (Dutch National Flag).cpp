class Solution {
public:
    void sortColors(vector<int>& nums) {
        // so the idea here is to have 3 pointers start, mid and end
        // all the eles to the left of start will be 0, and all the eles to the right end will be 2s and in b/w from start to end we'll have all 1s
        int start = 0, mid = 0, end = nums.size()-1;
        while (mid <= end) {
            if (nums[mid] == 0) {
                // we want to place all 0s to the left of start
                swap(nums[start], nums[mid]);
                start++; // so that all 0s are to the left of start 
                mid++;
            }
            else if (nums[mid] == 1) {
                // now as we know all the region in b/w start and end [inclusive] is to be filled with 1s, so we don't do anything
                continue;
            }
            else {
                // we want to place all the 2s to the right of end
                swap(nums[end], nums[mid]);
                end--; // now unlike nums[i] == 1 case, we don't increment mid because there's a possibility that the sswapped nums[end] ele again requires a swapping the the left
            }
        }
    }
};
