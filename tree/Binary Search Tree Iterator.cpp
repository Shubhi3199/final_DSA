class BSTIterator {
public:
    TreeNode* root;
    stack<TreeNode*> st;
    void insert_left(TreeNode* node) {
        // insert all the nodes to the left of the cur node in the stack till we reach the extreme left (smallest node in the cur subtree)
        while (node -> left) {
            st.push(node -> left);
            node = node -> left;
        }
    }
    BSTIterator(TreeNode* r) {
        root = r;
        st.push(root);
        insert_left(root);
    }
    
    int next() {
        if (st.empty() == true) return -1;
        TreeNode* cur = st.top();
        st.pop();
        int val = cur -> val;
        if (cur -> right) {
            st.push(cur -> right);
            insert_left(cur -> right);
        }
        return val;
    }
    
    bool hasNext() {
        if (st.empty() == true) return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
