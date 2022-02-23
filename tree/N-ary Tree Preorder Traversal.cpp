/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        if (root == NULL) return {};
        stack<Node*> st;
        vector<int> pre_res;
        st.push(root);
        while (st.empty() == false) {
            Node* cur_node = st.top();
            st.pop();
            pre_res.push_back(cur_node -> val);
            for (int idx = (cur_node -> children).size()-1; idx >= 0 and (cur_node -> children)[idx] != NULL; idx--) {
                st.push(cur_node -> children[idx]);
            }
        }
        return pre_res;
    }
};
