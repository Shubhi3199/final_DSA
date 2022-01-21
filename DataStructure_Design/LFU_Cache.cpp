// https://leetcode.com/problems/lfu-cache/
class Node {
public:
    int key, val, cnt;
    Node* prev, *next;
    Node(int _key, int _val) {
        key = _key;
        val = _val;
        cnt = 1; // cnt is the freq of this node
    }
};

class List {
public:
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    int size; // size of the DLL
    List() {
        head -> next = tail;
        tail -> prev = head;
        size = 0;
    }
    void add_node(Node* node) {
        Node* temp = head -> next;
        head -> next = node;
        node -> prev = head;
        node -> next = temp;
        temp -> prev = node;
        size++;
    }
    void remove_node(Node* node) {
        node -> prev -> next = node -> next;
        node -> next -> prev = node -> prev;
        size--;
    }
};
class LFUCache {
    unordered_map<int, Node*> key_node_map; // To map keys with corresponding nodes in the DLL for accessing the nodes in O(1) time
    unordered_map<int, List*> freq_list_map; // To map all the nodes with a particular freq as a list, so that if there's a tie while removing the least frequently used node (LFU), we can get rid of the least recently used (LRU) node as the list is maintained in LRU pattern 
    int max_size;
    int cur_size;
    int min_freq; // so as to find which node is with the least freqency and thus be deleated in O(1) time
public:
    LFUCache(int capacity) {
        max_size = capacity;
        cur_size = 0;
        min_freq = 0;
    }
    
    void update_freqmap(Node* node) {
        // Step1: Remove the node from its current frequency list
        freq_list_map[node -> cnt] -> remove_node(node); 
        // Step2: update the min_freq if the removed node was the last node of minnimum frequency list
        if (node -> cnt == min_freq and freq_list_map[node -> cnt] -> size == 0) {
            min_freq++; // as we are not left with any node with the prev min_freq;
        }
        // Step3: Insert this node into a higher freq list than it's current frequency
        List* higher_frequency_list = new List();
        if (freq_list_map.count(node -> cnt + 1) == true) {
            higher_frequency_list = freq_list_map[node -> cnt + 1];
        }
        node -> cnt += 1;
        higher_frequency_list -> add_node(node);
        freq_list_map[node -> cnt] = higher_frequency_list;
    }
    
    int get(int key) {
        if (key_node_map.count(key) == false) return -1;
        Node* node = key_node_map[key];
        int val = node -> val;
        update_freqmap(node); // as we just now accessed the node, so we'll have to update its freq in the freq_list_map
        return val;
    }
    
    void put(int key, int value) {
        if (max_size == 0) return; // as the capacity of our LFU cache is 0
        if (key_node_map.count(key)) {
            // if the key already exists in the key_node_map
            Node* node = key_node_map[key];
            node -> val = value;
            update_freqmap(node);
        }
        else { 
            if (cur_size == max_size) {
                // so we need to remove the least frequently used node
                List* least_frequent_list = freq_list_map[min_freq]; // list containing nodes that are least frequently used
                // if there are more than 1 nodes in this least frequent list, that means we'll get rid of LRU node
                // Ste1: removing from the hashmap
                key_node_map.erase(least_frequent_list -> tail -> prev -> key); 
                // Step2: removing node from the DLL
                freq_list_map[min_freq] -> remove_node(least_frequent_list -> tail -> prev);
                cur_size--;
            }
            // Now insert a new Node with (key, value)
            cur_size++; // on insertion of a new node
            min_freq = 1; // as we are inserting this node for the first time, so definitey the min_freq will be reset to 1
            List* freq_list = new List();
            if (freq_list_map.count(min_freq) == true) {
                freq_list = freq_list_map[min_freq];
            }
            Node* new_node = new Node(key, value);
            freq_list -> add_node(new_node);
            key_node_map[key] = new_node;
            freq_list_map[min_freq] = freq_list;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
