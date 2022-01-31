class Solution {
public:
    int get_diameter(TreeNode* root, int &max_diam) {
        if (root == NULL) return 0;
        int left_height = get_diameter(root -> left, max_diam);
        int right_height = get_diameter(root -> right, max_diam);
        max_diam = max(max_diam, left_height + right_height);
        return max(left_height, right_height) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int max_diam = 0;    
        get_diameter(root, max_diam);
        return max_diam;
    }
};
