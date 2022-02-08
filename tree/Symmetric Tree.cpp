// Iterative
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        queue<TreeNode*> q;
        if (root -> left == NULL and root -> right == NULL) return true;
        q.push(root -> left);
        q.push(root -> right);
        while (q.empty() == false) {
            TreeNode* leftptr = q.front();
            q.pop();
            TreeNode* rightptr = q.front();
            q.pop();
            if (leftptr == NULL or rightptr == NULL) return false;
            if (leftptr -> val != rightptr -> val) return false;
            // so the above lines ensure that the ee till the current level are symmetric now we need to check for the subtrees
            // To ensure symmetry, the subtree should follow 2 conditions:
            // 1. leftptr -> left (symmetric with) rightptr -> right
            // 2. leftptr -> right (symmetric with) rightptr -> left
            if (leftptr -> left or rightptr -> right) {
                q.push(leftptr -> left);
                q.push(rightptr -> right);
            }
            if (leftptr -> right or rightptr -> left) {
                q.push(leftptr -> right);
                q.push(rightptr -> left);
            }
            
        }
        return true;
    }
};

// Recursive
class Solution {
public:
    bool check_symmetry(TreeNode *left, TreeNode *right) {
        // A tree is symmetric if the left subtree is a mirror reflection of the right subtree.
        // Base case: 
        if (left == NULL or right == NULL) {
            return left == right; // returns true if the both left and right subtree becomes null together, other wise false.
        }
        // Now the most basic check for a subtree to be symmetric is to check if the current non-null left and right values are equal
        if (left -> val != right -> val) return false;
        // Recursion case: 
        // Now after confirming the equality of current left subtree's root and right subtree's root, we need to make sure about 2 cases for symmetry check
        // 1. left subtree's left is symentric with right subtree's right
        // 2. left subtree's right is symmetric with right subtee's left
        return check_symmetry(left -> left, right -> right) and check_symmetry(left -> right, right -> left);
    }
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return check_symmetry(root -> left, root -> right);
    }
};
