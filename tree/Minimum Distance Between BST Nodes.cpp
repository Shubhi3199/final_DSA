// https://leetcode.com/problems/minimum-distance-between-bst-nodes/
class Solution {
public:
    void get_min_diff(TreeNode* root, int min_val, int max_val, int &min_diff) {
        if (root == NULL) return;
        int value = root -> val;
        min_diff = min({min_diff, abs(min_val - value), abs(max_val - value)});
        get_min_diff(root -> left, min_val, value, min_diff);
        get_min_diff(root -> right, value, max_val, min_diff);
    }
    int minDiffInBST(TreeNode* root) {
        int min_diff = INT_MAX;
        get_min_diff(root, INT_MAX, INT_MAX, min_diff);
        return min_diff;
    }
};
