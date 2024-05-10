class Node {
    Node* list[26];
    bool flag;
    public:
    Node(){
        flag = false;

        for(int i=0; i<26; i++){
            list[i] = nullptr;
        }
    }

    void add(char ch, Node* node){
        list[ch-'a'] = node;
    }

    bool containsKey(char ch){
        return list[ch-'a'] !=nullptr;
    }

    Node* get(char ch){
        return list[ch-'a'];
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* temp = root;

        for(int i=0; i<word.length(); i++){

            if(!temp->containsKey(word[i])){
                temp->add(word[i],new Node());
            }

            temp = temp->get(word[i]);

        }

        temp->setEnd();
        
    }
    
    bool search(string word) {
        Node* temp = root;

        for(int i=0; i<word.length(); i++){
            if(!temp->containsKey(word[i])){
                return false;
            }

            temp = temp->get(word[i]);
        }

        return temp->isEnd();
        
    }
    
    bool startsWith(string word) {
        Node* temp = root;

        for(int i=0; i<word.length(); i++){
            if(!temp->containsKey(word[i])){
                return false;
            }

            temp = temp->get(word[i]);
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */