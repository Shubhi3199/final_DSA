/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) return root;
        Node* head = root;
        while (head) {
            Node* cur = head; // cur is the node in the cur level, so that after dealing with the head node in the current level, we can move horizontally in this level to make all the connections in the next level
            Node* next_level_node = NULL, *next_level_head = NULL;
            while (cur) {
                if (cur -> left) {
                    // q.push(cur -> left);
                    if (next_level_head == NULL) next_level_head = cur -> left;
                    if (next_level_node == NULL) next_level_node = cur -> left;
                    else {
                        next_level_node -> next = cur -> left;
                        next_level_node = next_level_node -> next;
                    }
                }
                if (cur -> right) {
                    // q.push(cur -> right);
                    if (next_level_head == NULL) next_level_head = cur -> right;
                    if (next_level_node == NULL) next_level_node = cur -> right;
                    else {
                        next_level_node -> next = cur -> right;
                        next_level_node = next_level_node -> next;
                    }
                }
                cur = cur -> next;
            }
            head = next_level_head;
        }
        return root;
    }
};
