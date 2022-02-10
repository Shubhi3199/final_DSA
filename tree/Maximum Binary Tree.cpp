class Solution {
public:
    TreeNode* construct_btree(int start, int end, vector<int> &nums) {
        if (start > end) return NULL; //when we have nothing on the left/right subtree
        if (start == end) {
            return new TreeNode(nums[start]);
        }
        TreeNode* root;
        // Step1: Find the max ele in the current range [start, end]
        int max_idx = start;
        for (int idx = start; idx <= end; idx++) {
            if (nums[idx] > nums[max_idx]) max_idx = idx;
        }
        // Step2: create a node with the max ele as the root of the cur subtree
        root = new TreeNode(nums[max_idx]);
        // Step3: Make the left and right connections
        root -> left = construct_btree(start, max_idx-1, nums);
        root -> right = construct_btree(max_idx + 1, end, nums);
        return root;
    } 
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construct_btree(0, nums.size()-1, nums);
    }
};
