/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // serializing the tree as a levelorder string and wherever ther's a null node, "#" string can be added  
        string levelorder = "";
        if (root == NULL) return levelorder;
        queue<TreeNode*> nodes_queue;
        nodes_queue.push(root);
        while (nodes_queue.empty() == false) {
            int size = nodes_queue.size();
            for (int cnt = 0; cnt < size; cnt++) {
                TreeNode* node = nodes_queue.front();
                nodes_queue.pop();
                if (node == NULL) levelorder += "#,";
                else {
                    levelorder += to_string(node -> val);
                    levelorder += ',';
                }
                if (node != NULL) {
                    // if the cur node is not null then ww'll definitely push both it's children into the queue irrespective of the fact that they are null nodes or not, as in levelorder traversal we require exact position of nodes so null nodes are necessary
                    nodes_queue.push(node -> left);
                    nodes_queue.push(node -> right);
                }
            }
        }
        return levelorder;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0) return NULL;
        stringstream s(data); // to iterate easily on the comma-seperated input string data
        string str;
        getline(s, str, ','); // this function gives the next string after the ','
        TreeNode* root = NULL; // root of the final tree that we'll generate now
        if (str != "#") root = new TreeNode(stoi(str));
        queue<TreeNode*> nodes_queue;
        if (root != NULL) nodes_queue.push(root);
        while (nodes_queue.empty() == false) {
            int size = nodes_queue.size();
            for (int cnt = 0; cnt < size; cnt++) {
                TreeNode* cur_node = nodes_queue.front();
                nodes_queue.pop();
                // Now we'll connect the next node in the levelorder traversal to the left of the cur_node and the 2nd next node to the right of the cur_node irrespective of the fact that they are null or not
                getline(s, str, ',');
                if (str == "#") {
                    cur_node -> left = NULL;
                }
                else {
                    TreeNode* new_node = new TreeNode(stoi(str));
                    cur_node -> left = new_node;
                    nodes_queue.push(new_node);
                }
                // Now we want to fill the right child of the cur_node, so we acess the next available node in the input string data by using getline
                getline(s, str, ',');
                if (str == "#") {
                    cur_node -> right = NULL;
                }
                else {
                    TreeNode* new_node = new TreeNode(stoi(str));
                    cur_node -> right = new_node;
                    nodes_queue.push(new_node);
                }
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
