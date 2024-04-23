

class LRUCache {
public:

 class Node{
    public:
        int key;
        int val;
        Node* prev;
        Node* next;
    
        Node(int key, int val){
            this->key = key;
            this->val = val;
        }

    };
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    int cap;

    unordered_map<int,Node*> mp;


    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
        
    }
    
    int get(int key) {

        if(mp.find(key)!=mp.end()){
            Node* node = mp[key];
            int ans = node->val;

            mp.erase(key);
            deleteNode(node);
            addNode(node);
            mp[key] = head->next;
            return ans;


        }

        return -1;

        
    }

    void addNode(Node* node){
        // if(head->next!=nullptr){
            Node* next = head->next;

            head->next = node;
            node->next = next;
            next->prev = node;
            node->prev = head;

        //     return;
        // }

        // head->next = node;
        // node->prev = head;


    }

    void deleteNode(Node* node){

        Node* prev = node->prev;
        Node* next = node->next;

        prev->next = next;
        next->prev = prev;



    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            /// map me hai.. delete then insert again.
            Node* curr = mp[key];
            mp.erase(key);
            deleteNode(curr);
        }

        // put krne jaa rhe agr cap reached hai to least ercently used has to be deleted.

        if(mp.size() == cap){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        addNode(new Node(key,value));
        mp[key] = head->next;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */