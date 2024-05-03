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
    int cap;
    unordered_map<int, Node*> keys;

public:
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
        // keys.resize(capacity);
    }

    void deleteNode(Node* node) {
        Node* nextOfDelete = node->next;
        Node* prevOfDelete = node->prev;
       
       prevOfDelete->next = nextOfDelete;
       nextOfDelete->prev = prevOfDelete;
    }

    void addNode(Node* node) {

        Node* next = head->next;

        head->next = node;
        node->next = next;
        next->prev = node;
        node->prev = head;
    }

    int get(int key) {

        if (keys.find(key) != keys.end()) {
            Node* node = keys[key];
            int res = node->value;
            keys.erase(key);
            deleteNode(node);
            addNode(node);
            keys[key] = head->next;
            return res;
        }

        return -1;
    }

    void put(int key, int value) {

        if (keys.find(key) != keys.end()) {
            Node* node = keys[key];
            // node->value = value;
            deleteNode(node);
            keys.erase(key);
        }

        if (keys.size() == cap) {
            keys.erase(tail->prev->key);
            deleteNode(tail->prev);
            // size--;
        }

        // size++;


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