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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> level_order;
        if (root == NULL) return level_order;
        queue<Node*> q;
        q.push(root);
        while (q.empty() == false) {
            int size = q.size();
            vector<int> cur_level(size);
            for (int idx = 0; idx < size; idx++) {
                Node* cur_node = q.front();
                q.pop();
                cur_level[idx] = cur_node -> val;
                for (Node* child: cur_node -> children) {
                    q.push(child);
                }
            }
            level_order.push_back(cur_level);
        }
        return level_order;
    }
};
