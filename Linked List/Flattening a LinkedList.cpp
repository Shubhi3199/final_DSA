/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

class Solution {
public:
    Node* merge_linkedlist(Node* l1, Node* l2) {
        Node* temp = new Node(-1);
        Node* res = temp;
        while (l1 != NULL and l2 != NULL) {
            if (l1 -> data < l2 -> data) {
                temp -> bottom = l1;
                temp = temp -> bottom;
                l1 = l1 -> bottom;
            }
            else {
                temp -> bottom = l2;
                temp = temp -> bottom;
                l2 = l2 -> bottom;
            }
        }
        if (l1) temp -> bottom = l1;
        else temp -> bottom = l2;
        return res -> bottom;
    } 
    Node *flatten(Node *root)
    {
        // We recursively go to the last node in the linkedist and start flattening the last 2 nodes
        if (root == NULL or root -> next == NULL) return root;
        root -> next = flatten(root -> next); // recursively calling the flatten function on the next LL and storing the ans of last 2 linkedlist in the next of linkedlist just before them
        // Step2 : merge sort the 2 linkedlist at hand
        root = merge_linkedlist(root, root -> next);
        return root;
    }
};
