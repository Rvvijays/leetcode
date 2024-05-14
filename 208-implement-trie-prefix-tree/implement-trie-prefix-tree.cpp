class TrieNode {

    unordered_map<char,TrieNode*> children;
    char ch;
    bool flag;

    public:
    TrieNode() {
        flag = false;
    }

    TrieNode* get(char ch) {
        return children[ch];
    }

    bool contains(char ch) {
        return children.find(ch) != children.end();
    }

    void add(char ch) {
        children[ch] = new TrieNode();
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }

};

class Trie {

    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* iterator = root;
        for (int i=0; i<word.size(); i++) {
            if(!iterator->contains(word[i])){
                iterator->add(word[i]);
            }

            iterator = iterator->get(word[i]);
        }

        iterator->setEnd();
    }
    
    bool search(string word) {
        TrieNode* iterator = root;
        for (int i=0; i<word.size(); i++) {
            if(!iterator->contains(word[i])){
                return false;
            }

            iterator = iterator->get(word[i]);
        }

        return iterator->isEnd();
        
    }
    
    bool startsWith(string word) {
        TrieNode* iterator = root;
        for (int i=0; i<word.size(); i++) {
            if(!iterator->contains(word[i])){
                return false;
            }

            iterator = iterator->get(word[i]);
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