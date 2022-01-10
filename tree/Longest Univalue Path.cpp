/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int longest_path(TreeNode* root, int &max_val) {
        if (root == NULL) return 0;
        int cur = root -> val;
        int left_path = 0, right_path = 0;
        if (root -> left) {
            if (root -> left -> val == cur) {
                left_path = longest_path(root -> left, max_val);
            }
            else longest_path(root -> left, max_val);
        }
        if (root -> right) {
            if (root -> right -> val == cur) {
                right_path = longest_path(root -> right, max_val);
            }
            else longest_path(root -> right, max_val);
        }
        max_val = max(max_val, left_path + right_path + 1);
        return max(left_path, right_path) + 1;
    }
    int longestUnivaluePath(TreeNode* root) {
        int max_val = 0;
        longest_path(root, max_val);
        return max_val == 0 ? 0 : max_val - 1;
    }
};

// [1,null,4,4,4,null,null,4,5]
// [5,4,5,4,4,null,5,null,null,null,null,5,5,null,null,null,5]
