// recursive solution
class Solution {
public:
    void postorder(TreeNode* root, vector<int> &res) {
        if (root == NULL) return;
        postorder(root -> left, res);
        postorder(root -> right, res);
        res.push_back(root -> val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorder(root, res);
        return res;
    }
};

// Iterative - Time -> O(N^2),  as insert operation is costly in vector
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == NULL) return {};
        vector<int> res;
        stack<TreeNode*> st;
        st.push(root);
        while (st.empty() == false) {
            TreeNode* node = st.top();
            st.pop();
            res.insert(res.begin(), node -> val); // Every time I/m pushhing the node at the front of the vector, so that the first node pushed is actually the last in vector, and thus postorder. 
            // Also, we are pushing the left node before the right node as we are inserting the node in the front of the vector, so if the st has right subtree root on the top so it will be inserted in the vector before the left oone and thus the left -> right -> root order is preserved
            if (node -> left) st.push(node -> left);
            if (node -> right) st.push(node -> right);
        }
        return res;
    }
};
