class LRUCache {
public:
    class Node {
    public:
        int key, value;
        Node* next, *prev;
        Node(int _key, int _value) {
            key = _key;
            value = _value;
        }
    };
    
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1); // head and tail are the dummy nodes that define are LRU cache, the moost recently used page will be located to the next of head and the least recently used page will be located to the prev of the tail.
    
    unordered_map<int, Node*> page_map; // used to access the page in the DLL in O(1) time
    int size; // max_size of the LRU cache
    
    LRUCache(int capacity) {
        size = capacity;
        head -> next = tail;
        tail -> prev = head;
    }
    
    // delete_node and add_node only modify the DLL, get() and put() are used to modify the page_map 
    void delete_node(Node* node) {
        node -> prev -> next = node -> next;
        node -> next -> prev = node -> prev;
    }
    
    void add_node(Node* node) {
        Node* temp = head -> next;
        node -> next = temp;
        temp -> prev = node;
        head -> next = node;
        node -> prev = head;
    }
    
    int get(int key) {
        if (page_map.count(key) == false) return -1;
        int val = page_map[key] -> value;
        Node* node = page_map[key];
        page_map.erase(key);
        delete_node(node);
        add_node(node); // add node to head -> next as this is the most recently used node
        page_map[key] = head -> next;
        return val;
    }
    
    void put(int key, int value) {
        if (page_map.count(key)) {
            // the key already exists and we just update the value and add the node as most recently used
            delete_node(page_map[key]);
            page_map.erase(key);
        }
        if (page_map.size() == size) {
            // over flow condition, so we get rid of the least recently used page (tail -> prev)
            page_map.erase(tail -> prev -> key);
            delete_node(tail -> prev);
        }
        add_node(new Node(key, value));
        page_map[key] = head -> next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
