class Solution {
public:
    int count_nodes(TreeNode* root, int red_node, int &max_nodes) {
        if (root == NULL) return 0;
        int left_cnt = count_nodes(root -> left, red_node,max_nodes);
        int right_cnt = count_nodes(root -> right, red_node, max_nodes);
        if (root -> val == red_node) return 0;
        max_nodes = max(max_nodes, left_cnt + right_cnt + 1
        return left_cnt + right_cnt + 1;
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        int max_nodes = 0;
        count_nodes(root, x, max_nodes);
        cout<<max_nodes<<endl;
        if (n - max_nodes > max_nodes) return false; // as the number of red nodes will be greater than blue nodes definitely
        return true;
    }
};

