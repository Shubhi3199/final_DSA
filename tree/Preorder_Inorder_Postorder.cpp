class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == NULL) return {};
        vector<int> preorder, inorder, postorder;
        stack<pair<TreeNode*, int>> st; // {node, state}, 1 -> preorder, 2 -> inorder, 3 -> postorder
        st.push({root, 1});
        while (st.empty() == false) {
            TreeNode* node = st.top().first;
            int state = st.top().second;
            st.pop();
            if (state == 1) {
                // that means the node is currently in the epreorder traversal
                preorder.push_back(node -> val);
                st.push({node, state + 1}); // so that the next time we encounter it, it must be in inorder traversal
                if (node -> left) st.push({node -> left, 1}); // as after preorder we traverse to the left subtree
            }
            else if (state == 2) {
                // in inorder traversal
                inorder.push_back(node -> val);
                st.push({node, state + 1});
                if (node -> right) st.push({node -> right, 1}); // as after inorder we traverse to the right subtree
            }
            else {
                // we are in the postorder
                postorder.push_back(node -> val);
            }
        }
        return postorder;
    }
};
