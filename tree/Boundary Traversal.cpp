// https://www.codingninjas.com/codestudio/problems/boundary-traversal_790725?leftPanelTab=0
#include<bits/stdc++.h>
bool is_leaf(TreeNode<int> *root) {
    return root -> left == NULL and root -> right == NULL;
}
void get_left_boundary(TreeNode<int> *root, vector<int> &boundary) {
    TreeNode<int> *cur = root -> left;    
    while (cur) {
        if (is_leaf(cur) == false) boundary.push_back(cur -> data);
        if (cur -> left) cur = cur -> left;
        else cur = cur -> right;
    }
}
void get_right_boundary(TreeNode<int> *root, vector<int> &boundary) {
    TreeNode<int> *cur = root -> right;
    stack<int> st;
    while (cur) {
        if (is_leaf(cur) == false) st.push(cur -> data);
        if (cur -> right) cur = cur -> right;
        else cur = cur -> left;
    }
    while (st.empty() == false) {
        boundary.push_back(st.top());
        st.pop();
    }
}

void get_leaves(TreeNode<int> *root, vector<int> &boundary) {
    if (root == NULL) return;
	if (is_leaf(root) == true) boundary.push_back(root -> data);
    get_leaves(root -> left, boundary);
    get_leaves(root -> right, boundary);
}

vector<int> traverseBoundary(TreeNode<int>* root){
    if (root == NULL) return {};
    vector<int> boundary;
    boundary.push_back(root -> data);
    if (root -> left == NULL and root -> right == NULL) return boundary;
    get_left_boundary(root, boundary);
    get_leaves(root, boundary);
    get_right_boundary(root, boundary);
    return boundary;
}
