class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        // we are going to go and validate on each node, if the cur node is valid, then we go to both the lefgt and the right subtree to validate recursively but if the cur node is invalid then we get rid of the cur node and one of it's subtree (either left or right) based upon invaid condition
        if (root == NULL) return root;
        int value = root -> val;
        if (value >= low and value <= high) {
            root -> left = trimBST(root -> left, low, high);
            root -> right = trimBST(root -> right, low, high);
        }
        else if (value < low) {
            // completely discard the left subtree and the cur node
            return trimBST(root -> right, low, high);
        }
        else {
            // ignore the cur node and the entire right subtree
            return trimBST(root -> left, low, high);
        }
        return root;
    }
};
