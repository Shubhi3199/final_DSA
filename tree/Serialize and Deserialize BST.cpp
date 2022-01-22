/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


// Seerialize by performing preorder traversal and then desrialze by using the same in O(N) time by using the core property of BST (IMP)
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string preorder = "";
        _serialize(root, preorder);
        return preorder;
    }
    
    void _serialize(TreeNode* root, string &preorder) {
        if (root == NULL) return;
        preorder += to_string(root -> val);
        preorder += ',';
        _serialize(root -> left, preorder);
        _serialize(root -> right, preorder);
    }

    // Decodes your encoded data to tree.
    TreeNode* _deserialize(string data, int &idx, int min_value, int max_value) {
        if (idx >= data.size()) return NULL;
        int value = 0;
        int i = idx;
        while (data[i] != ',') {
            value *= 10;
            value += data[i] - '0';
            i++;
        }
        i += 1;
        TreeNode *node = NULL;
        if (value >= min_value and value <= max_value) {
            node = new TreeNode(value);
        }
        if (node == NULL) return NULL;
        idx  = i;
        node -> left = _deserialize(data, idx, min_value, value - 1); // call to left subtree
        node -> right = _deserialize(data, idx, value - 1, max_value);
        return node;
    }
    
    TreeNode* deserialize(string data) {
        int idx = 0;
        return _deserialize(data, idx, 0, 10000);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
