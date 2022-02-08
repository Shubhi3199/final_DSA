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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        if (root == NULL) return vector<ListNode*> (k);
        int size = get_ll_length(root);
        vector<ListNode*> res;
        // cur_size => The length of the remaining list to be inserted in the res vector
        // left_spaces => number of vacant spaces left in the res array which was intialized to be divided into k nodes
        int cur_size = size, left_spaces = k, part_len = 0;
        while (left_spaces != 0) {
            part_len = cur_size / left_spaces; // len of the cur partition to be made
            if (cur_size % left_spaces != 0 or part_len <= 0) part_len++;
            if (cur_size > 0) cur_size -= part_len;
            left_spaces--;
            ListNode* prev = NULL;
            res.push_back(root);
            while (part_len != 0) {
                prev = root;
                if (root) root = root -> next;
                part_len--;
            }
            if (prev) prev -> next = NULL;
        }
        
        return res;
    }
};
