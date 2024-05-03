
class Node {

public:
    int key;
    int value;
    int freq;
    Node* next;
    Node* prev;
    Node(int key, int value) {
        this->key = key;
        this->value = value;
        next = nullptr;
        prev = nullptr;
        freq = 1;
    }
};
class NodeList {

public:
    Node* head;
    Node* tail;
    int size;

    NodeList() {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addNode(Node* node) {
        Node* next = head->next;

        head->next = node;
        node->next = next;
        node->prev = head;
        next->prev = node;
        size++;
    }

    void deleteNode(Node* node) {
        Node* next = node->next;
        Node* prev = node->prev;

        prev->next = next;
        next->prev = prev;
        size--;
    }
};

class LFUCache {
    unordered_map<int, Node*> keyMap;
    unordered_map<int, NodeList*> freqMap;
    int capacity;
    int minFreq;
    int currSize;

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
        currSize = 0;
    }

    int get(int key) {

        if (keyMap.find(key) != keyMap.end()) {
            Node* node = keyMap[key];
            int ans = node->value;

            updateFreqList(node);
            return ans;
        }
        return -1;
    }

    void updateFreqList(Node* node) {
        keyMap.erase(node->key);
        freqMap[node->freq]->deleteNode(node);
        if (node->freq == minFreq && freqMap[node->freq]->size == 0) {
            minFreq++;
        }

        NodeList* nextList = new NodeList();

        if (freqMap.find(node->freq + 1) != freqMap.end()) {
            nextList = freqMap[node->freq + 1];
        }

        node->freq += 1;

        nextList->addNode(node);
        freqMap[node->freq] = nextList;
        keyMap[node->key] = node;
    }

    void put(int key, int value) {

        if (capacity == 0) {
            return;
        }

        if (keyMap.find(key) != keyMap.end()) {
            // delete hogi
            // freq update hogi.
            Node* node = keyMap[key];
            node->value = value;
            // keyMap.remove(key);
            updateFreqList(node);

        } else {

            if (currSize == capacity) {
                NodeList* list = freqMap[minFreq];
                keyMap.erase(list->tail->prev->key);
                freqMap[minFreq]->deleteNode(list->tail->prev);
                currSize--;
            }

            currSize++;
            minFreq = 1;
            NodeList* listFreq = new NodeList();

            if (freqMap.find(minFreq) != freqMap.end()) {
                listFreq = freqMap[minFreq];
            }

            Node* node = new Node(key, value);
            listFreq->addNode(node);
            keyMap[key] = node;
            freqMap[minFreq] = listFreq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */