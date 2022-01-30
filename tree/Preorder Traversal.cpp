// recursive Solution
class Solution {
public:
    void preorder(TreeNode* root, vector<int> &res) {
        if (root == NULL) return;
        res.push_back(root -> val);
        preorder(root -> left, res);
        preorder(root -> right, res);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorder(root, res);
        return res;
    }
};

// Iterartive Solution
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        if (root == NULL) return {};
        st.push(root);
        while (st.empty() == false) {
            TreeNode* cur_node = st.top();
            st.pop();
            res.push_back(cur_node -> val);
            // We add the right node before the left node in the stack as in preorder traversal fter printing the cur_node, we want to travere the left subtree before going on to the right one and as the stack is LIFO based, then  inserting right before left subtree in the stack will wnsure that the top node in stack is left subtree
            if (cur_node -> right) st.push(cur_node -> right);
            if (cur_node -> left) st.push(cur_node -> left);
        }
        return res;
    }
};
