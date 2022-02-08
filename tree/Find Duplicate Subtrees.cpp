/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    string serialize_subtree(TreeNode* root, unordered_map<string, int> &visited, vector<TreeNode*> &all_duplicates) {
        if (root == NULL) return "X";
        string cur_str = to_string(root -> val);
        cur_str = "_" + cur_str; // so that we can handle edge case, where serialization of different subtree results into the same string, ex: (1, 11) subtree forms => 111XXX and (11, 1) also forms 111XXX string
        string left_subtree = serialize_subtree(root -> left, visited, all_duplicates);
        string right_subtree = serialize_subtree(root -> right, visited, all_duplicates);
        cur_str += (left_subtree + right_subtree);
        if (visited.count(cur_str) == false) visited[cur_str] = 1;
        else if (visited[cur_str] == 1) {
            all_duplicates.push_back(root);
            visited[cur_str]++;
        }
        return cur_str;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> all_duplicates;
        if (root == NULL) return all_duplicates;
        unordered_map<string, int> visited;
        serialize_subtree(root, visited, all_duplicates);
        return all_duplicates;
    }
};

// [1,2,2,3,4,3,4,null,9,null,5,9,null,null,5,10,null,null,null,10]
// [1,2,2,3,4,3,4,9,null,5,9,9,null,5,9,null,null,null,10,null,null,null,null,null,10]
