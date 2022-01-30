// Time - O(N + M), Space - O(1)
class Solution
{
public:
    int intersectPoint(Node* head1, Node* head2)
    {
        Node* t1 = head1, *t2 = head2;
        while (t1 != NULL or t2 != NULL) {
            if (t1 == t2) return t1 -> data;
            if (t1) t1 = t1 -> next;
            else t1 = head2;
            if (t2) t2 = t2 -> next;
            else t2 = head1;
        }
        return -1;
    }
};
