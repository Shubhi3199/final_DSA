/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    pair<ListNode*, ListNode*> get_mid(ListNode* head) {
        ListNode* slow = head, *fast = head, *prev = NULL;
        while (fast != NULL and fast -> next != NULL) {
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return {prev, slow}; // prev pointer to the mid is neccessary to be returned so as to make mid's prev node point to null as when we'll recursively make a call to mid's left then the last node in the left LL should not have a connection with the right half to avoid repetation 
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL) return NULL;
        // Step1: Get the mif node fron the current head and that mid will become the root of the current subtree as it will divide the LL in 2 equal left and right halfs and ifc we do this step recursively then everytime we'll have almost equal halves ensuring a height balanced BST
        pair<ListNode*, ListNode*> mid_pair = get_mid(head);
        ListNode* prev = mid_pair.first;
        ListNode* mid = mid_pair.second;
        TreeNode* root = new TreeNode(mid -> val);
        // Now mark prev -> next to NULL before passing head to the left half recursively
        if (prev) {
            prev -> next = NULL;
            root -> left = sortedListToBST(head); // we make left call only wjen prev != NULL as otherwise there must be just 1 node in the left LL which is alreadt the basce case
        }
        root -> right = sortedListToBST(mid -> next);
        return root;
    }
};
