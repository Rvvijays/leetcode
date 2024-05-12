/*

["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2],       [1, 1], [2, 2], [1], [3, 3],  [2],  [4, 4], [1],    [3],   [4]]

size = 2;

head -- >(4,4) --> (3,3) -->   --> tail

---> return 1
2,2
1,1
----> 

*/

class Node {
   
   
    
    public:
     Node* next;
    Node* prev;
     int key;
    int value;
    Node(int key, int value) {
        this->key = key;
        this->value = value;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {
    
    unordered_map<int,Node*> keys;
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    int size;
    public:
    LRUCache(int capacity) {
        size = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(Node* node) {
        Node* next = head->next;
        head->next = node;
        node->next = next;
        next->prev = node;
        node->prev = head;
    }
    
    void deleteNode(Node* node) {
        
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev= prev;
    }
    
    int get(int key) {
        if(keys.find(key)!=keys.end()) {
            Node* node = keys[key];
            int res = node->value;
            deleteNode(node);
            addNode(new Node(key,res));
            keys[key] = head->next;
            
            return res;
            
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        if(keys.find(key) != keys.end()) {
            Node* node = keys[key];
            deleteNode(node);
            keys.erase(key);
        }
        
        if(size == keys.size()) {
            keys.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        
        addNode(new Node(key,value));
        keys[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */