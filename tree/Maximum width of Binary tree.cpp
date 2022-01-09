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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        int max_width = 0;
        queue<pair<TreeNode*, int>> q; // {node, idx}
        q.push({root, 0});
        while (!q.empty()) {
            int size = q.size();
            int min_idx = q.front().second; // subtracted while calculating the next level nodes to avoid int overflow
            int left_idx = 0, right_idx = 0; // left idx is the leftmost idx in the current level and the right idx is the rightmost idx of the current level using which we'll calculate the width of the current level
            for (int i = 0; i < size; i++) {                 
                TreeNode* cur_node = q.front().first;
                int cur_idx = q.front().second - min_idx; // min_idx is subtracted to avoid integer overflow in cases of skewed tree
                q.pop();
                if (cur_node -> left) {
                    int next_idx = 2*cur_idx + 1; // left child is marked as 2*i+1, where i is the idx of the parent node
                    q.push({cur_node -> left, next_idx});
                }
                if (cur_node -> right) {
                    int next_idx = 2*cur_idx + 2; // right child is marked as 2*i+2
                    q.push({cur_node -> right, next_idx});
                }
                if (i == 0) left_idx = cur_idx;
                if (i == size - 1) right_idx = cur_idx;
            }
            max_width = max(max_width, right_idx - left_idx + 1); // computing the max_width of the cur level
        }
        return max_width;
    }
};


// https://leetcode.com/problems/maximum-width-of-binary-tree/
