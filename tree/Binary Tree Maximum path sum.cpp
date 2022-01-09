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
    int get_max_sum(TreeNode* root, int &max_sum) {
        if (root == NULL) return 0;
        int max_left_sum = max(0, get_max_sum(root -> left, max_sum)); // getting the max sum from the left subtree and if the max_sum from the left/right is -ve then  we take a 0 as previous negative sum will never lead to a larger max_sum (kadanes's algo)
        int max_right_sum = max(0, get_max_sum(root -> right, max_sum));
        max_sum = max(max_sum, root -> val + max_left_sum + max_right_sum); // here we find out the max_sum at the cur node forming a umbrella like structure
        return root -> val + max(max_left_sum, max_right_sum); // as the path from the parent of the cur root cannot involve an umbrella type structure, we return the max of left + root or right + root
    }
    int maxPathSum(TreeNode* root) {
        if (root == NULL) return 0;
        int max_sum = INT_MIN;
        get_max_sum(root, max_sum);
        return max_sum;
    }
};

// [10,9,-20,20,-5,-15,100,null,null,30,null,null,null,30]
// https://leetcode.com/problems/binary-tree-maximum-path-sum/
