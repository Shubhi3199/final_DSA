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
class Solution {
public:
    int get_ll_length(ListNode* head) {
        int len = 0;
        while (head) {
            len++;
            head = head -> next;
        }
        return len;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) return head;
        int size = get_ll_length(head);
        k = k % size;
        if (k == 0) return head;
        // Iterate to size-k node
        int it = 1;
        ListNode* cur = head;
        while (it < size - k) {
            cur = cur -> next;
            it++;
        }
        ListNode* temp = cur -> next;
        cur -> next = NULL;
        cur = temp;
        while (temp -> next != NULL) {
            temp = temp -> next;
        }
        temp -> next = head;
        return cur;
    }
};
