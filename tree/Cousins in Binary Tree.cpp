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
    bool isCousins(TreeNode* root, int x, int y) {
        if (root == NULL) return false; 
        queue<pair<TreeNode*, int>> q;
        q.push({root, -1});
        int par_x= -1, par_y = -1;
        while (q.empty() == false) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* cur = q.front().first;
                int par = q.front().second;
                q.pop();
                if (cur -> val == x) {
                    par_x = par;
                }
                else if (cur -> val == y) par_y = par;
                if (cur -> left) q.push({cur -> left, cur -> val});
                if (cur -> right) q.push({cur -> right, cur -> val});
            }
            // After we are over with the current level we'll check if the parents are different for the nodes at the cur level
            if (par_x != -1 and par_y != -1 and par_x != par_y) return true;
            else {
                // both will be reinitialized to -1 as the ans is not possible in the cur level 
                par_x = -1; par_y = -1; // so that it should not consider x and y in different levels to be the ans
            }
        }
        return false;
    }
};
