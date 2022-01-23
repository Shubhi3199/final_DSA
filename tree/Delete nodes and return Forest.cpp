class Solution {
public:
    bool delete_nodes(TreeNode* root, TreeNode* parent, int dir, int del_node, unordered_map<int, TreeNode*> &disjoint_trees) {
        if (root == NULL) return false;
        if (root -> val == del_node) {
            if (disjoint_trees.count(del_node)) {
                // the node we are trying to delete is already placed in disjoint_tree
                disjoint_trees.erase(del_node);
            }
            TreeNode* node = root;
            if (node -> left) {
                disjoint_trees[node -> left -> val] = node -> left;
            }
            if (node -> right) {
                disjoint_trees[node -> right -> val] = node -> right;
            }
            if (dir == 0 and parent) parent -> left = NULL;
            else if (dir == 1 and parent) parent -> right = NULL;
            return true;
        }
        bool left_search = delete_nodes(root -> left, root, 0, del_node, disjoint_trees);
        if (left_search) return true;
        bool right_search = delete_nodes(root -> right, root, 1, del_node, disjoint_trees);
        return right_search;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if (root == NULL) return {};
        unordered_map<int, TreeNode*> disjoint_trees;
        disjoint_trees[root -> val] = root;
        for (int del_node: to_delete) {
            for (pair<int, TreeNode*> tree: disjoint_trees) {
                if (delete_nodes(tree.second, NULL, -1, del_node, disjoint_trees) == true) break;
            }
        }
        vector<TreeNode*> forest;
        for (pair<int, TreeNode*> tree: disjoint_trees) {
            forest.push_back(tree.second);
        }
        return forest;
    }
};

// Better solution, time - O(N) & space - O(N)

// As we delete nodes from the tree, if go in downwards direction and delete, then we'll require to know the parent and also the direction from which we are coming, 
// so it's better to go down to the leaf node and the while returning back we ask the question if we need to delete this node because then we'll not loose any child 
// info aswell as not requre to store any extra parent,, direction information

class Solution {
public:
    TreeNode* remove_nodes(TreeNode* root, unordered_set<int> &delete_node, vector<TreeNode*> &forest) {
        if (root == NULL) return NULL; // base case
        
        // step1: travere all the way done untill you don't hit the base case\
        root -> left = remove_nodes(root -> left, delete_node, forest); // if the left child node is to be deleted then automatically this call will return a NULL setting the left child to be null 
        root -> right = remove_nodes(root -> right, delete_node, forest);
        
        // Step2: Now as we've traversed from both the children, now standing at the cur root node we've to decde of this node has to be deleted
        if (delete_node.count(root -> val)) {
            if (root -> left != NULL) forest.push_back(root -> left);
            if (root -> right != NULL) forest.push_back(root -> right);
            return NULL; // so that we can set this nodes parent's left or right respective child to null
        }
        return root; // if root is not be delted then it's passed as it is 
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> delete_node; // To know in O(1) time if to delete a node or not
        for (int node: to_delete) {
            delete_node.insert(node);
        }
        vector<TreeNode*> forest; // Consisting of trees that re left after deletion 
        remove_nodes(root, delete_node, forest);
        //  As we are following the bottom-up approach, so when we coe out of the recurssion and are standing at the root node, then also we'll make a check if this root node has to be delete or not
        if (delete_node.count(root -> val) == false) {
            // if (root -> left != NULL) forest.push_back(root -> left);
            // if (root -> right != NULL) forest.push_back(root -> right);
            forest.push_back(root);
        }
        // else forest.push_back(root);
        return forest;
    }
};
