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
    ListNode* get_mid(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while (fast != NULL and fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow; // points at the mid (in case of even number of nodes, it points at the later node)
    }
    int pairSum(ListNode* head) {
        if (head == NULL) return 0;
        // The idea is to reverse the right half of the LL, so that we can have 2 pointers, a head and a tail and at each iteration increament head by 1 and decrement tail by 1.
        // Step1: Reach to the first node of the right half (find mid)
        ListNode* cur = get_mid(head);
        ListNode* prev = NULL, *after = cur -> next;
        // Step2: Reverse the pointers of the right half
        while (cur) {
            cur -> next = prev;
            prev = cur;
            cur = after;
            if (cur) after = cur -> next;
        }
        ListNode *start = head, *end = prev;
        int max_twin_sum = 0;
        // Step3: Use 2 pointers to get the max_sum
        while (end) {
            // start will be non NULL until end is non NULL as we'll have the same number of nodes in the left and the right half (due to even size of the ll)
            max_twin_sum = max(max_twin_sum, start -> val + end -> val);
            start = start -> next;
            end = end -> next;
        }
        return max_twin_sum;
    }
};
