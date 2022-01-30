// Recursive solution 
class Solution {
public:
    void inorder(TreeNode* root, vector<int> &res) {
        if (root == NULL) return;
        inorder(root -> left, res);
        res.push_back(root -> val);
        inorder(root -> right, res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }
};

// Iterartive Solution
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == NULL) return {};
        vector<int> res;
        stack<TreeNode*> st; 
        st.push(root);
        TreeNode* cur = root;
        while (st.empty() == false) {
            while (cur) {
                cur = cur -> left;
                if (cur) st.push(cur);
            }
            // Now there's no more left subtree nodes and thus we can start to take node and go on to the right subtree
            cur = st.top();
            st.pop();
            res.push_back(cur -> val); // as we have completely traversed cur nodes left subtree
            cur = cur -> right;
            if (cur) st.push(cur);
        }
        return res;
    }
};
