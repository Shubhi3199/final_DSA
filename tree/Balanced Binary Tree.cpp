class Solution {
public:
    int get_height(TreeNode* root) {
        if (root == NULL) return 0;
        int left_height = get_height(root -> left);
        if (left_height == -1) return -1;
        int right_height = get_height(root -> right);
        if (right_height == -1) return -1;
        if (abs(left_height - right_height) > 1) return -1;
        return max(left_height, right_height) + 1;
    }
    bool isBalanced(TreeNode* root) {
        return get_height(root) != -1;
    }
};
