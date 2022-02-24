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
    pair<ListNode*, ListNode*> get_mid_node(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while (fast -> next != NULL and fast -> next -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return {slow, slow -> next}; // {prev_to_mid, mid}
    }
    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* head = NULL, *tail = NULL;
        while (head1 and head2) {
            if (head1 -> val < head2 -> val) {
                if (head == NULL) {
                    head = head1;
                    tail = head;
                }
                else {
                    tail -> next = head1;
                    tail = tail -> next;
                }
                head1 = head1 -> next;
            }
            else {
                if (head == NULL) {
                    head = head2;
                    tail = head;
                }
                else {
                    tail -> next = head2;
                    tail = tail -> next;
                }
                head2 = head2 -> next;
            }
        }
        if (head1 and tail) tail -> next = head1;
        else if (head2 and tail) tail -> next = head2;
        return head;
    }
    ListNode* sortList(ListNode* head) {
        if (head == NULL or head -> next == NULL) return head;
        pair<ListNode*, ListNode*> p = get_mid_node(head);
        ListNode* prev_to_mid = p.first, *mid = p.second;
        prev_to_mid -> next = NULL; // to seperate the cur LL into 2 subhalves
        // Now I'll recursivelly call this function and keep the faith that it will return me 2 sorted halves
        ListNode* head1 = sortList(head); // sorted LL1
        ListNode* head2 = sortList(mid); // sorted LL2
        // Now we'll merge the 2 sorted halves and return the merged sorted LL
        return merge(head1, head2);
    }
};
