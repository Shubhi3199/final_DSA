// recursive solution
// class Solution {
// public:
//     TreeNode* invertTree(TreeNode* root) {
//         if (!root) {
//             return NULL;
//         }
//         swap(root -> left, root -> right);
//         invertTree(root -> left);
//         invertTree(root -> right);
//         return root;
//     }
// };

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return root;
        queue<TreeNode*> nodes_queue;
        nodes_queue.push(root);
        while (nodes_queue.empty() == false) {
            int size = nodes_queue.size();
            for (int cnt = 0; cnt < size; cnt++) {
                TreeNode* cur_node = nodes_queue.front();
                nodes_queue.pop();
                swap(cur_node -> left, cur_node -> right);
                if (cur_node -> left) nodes_queue.push(cur_node -> left);
                if (cur_node -> right) nodes_queue.push(cur_node -> right);
            }
        }
        return root;
    }
};
