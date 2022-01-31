class Solution {
public:
    void dfs(TreeNode* root, int horizontal_level, int vertical_level, unordered_map<int, multiset<pair<int, int>>> &map, int &min_vertical, int &max_vertical) {
        if (root == NULL) return;
        // Step1: Insert the cur node in the cur vertical level
        map[vertical_level].insert({horizontal_level, root -> val});
        min_vertical = min(min_vertical, vertical_level);
        max_vertical = max(max_vertical, vertical_level);
        // Step2: Recusively go to the left & right subtree
        dfs(root -> left, horizontal_level+1, vertical_level-1, map, min_vertical, max_vertical);
        dfs(root -> right, horizontal_level+1, vertical_level+1, map, min_vertical, max_vertical);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // {vertiacal_level -> {{horizontal_level, node_val}, ...}}, as I'll be using dfs so maintaing the horizontal level is also necessary, thus we sort 1st n the basis of horizontal level and if that is same for two nodes then we select the smaller first
        unordered_map<int, multiset<pair<int, int>>> map;
        int min_vertical = 0, max_vertical = 0;
        dfs(root, 0, 0, map, min_vertical, max_vertical);
        
        vector<vector<int>> res;
        for (int level = min_vertical; level <= max_vertical; level++) {
            vector<int> cur_level;
            for (pair<int, int> p: map[level]) {
                cur_level.push_back(p.second);
            }
            res.push_back(cur_level);
        }
        return res;
    }
};
