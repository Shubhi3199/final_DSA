// Solution1: 
class Solution {
public:
    void get_sum(TreeNode* root, int &total_sum) {
        if (root == NULL) return;
        if (root -> val % 2 == 0) {
            if (root -> left) {
                if (root -> left -> left) total_sum += root -> left -> left -> val;
                if (root -> left -> right) total_sum += root -> left -> right -> val;
            }
            if (root -> right) {
                if (root -> right -> left) total_sum += root -> right -> left -> val;
                if (root -> right -> right) total_sum += root -> right -> right -> val;
            }
        }
        get_sum(root -> left, total_sum);
        get_sum(root -> right, total_sum);
    }
    int sumEvenGrandparent(TreeNode* root) {
        int total_sum = 0; // total sum of all the grand-children with an even grand-parent
        get_sum(root, total_sum);
        return total_sum;
    }
}; 

// Solution 2: Better code understandibility
class Solution {
public:
    int s=0;
    int sumEvenGrandparent(TreeNode* root) {
        fun(root,NULL,NULL);  //passing the root node with it's parent & grandparent as NULL
        return s;
    }
    void fun(TreeNode* root,TreeNode* parent,TreeNode* grandparent)
    {
        if(!root) return;  //if root is null then return 
        if(grandparent && grandparent->val%2==0)  //checking even valued grandparent existance 
            s+=root->val;
        fun(root->left,root,parent);  //calling function for left subtree where root will be the parent & previous parent will act as the grandparent for left subtree of the root.
        fun(root->right,root,parent);  //same for right subtree
    }
};
