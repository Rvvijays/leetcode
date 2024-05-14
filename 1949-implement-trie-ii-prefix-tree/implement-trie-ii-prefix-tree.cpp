class TrieNode {
    unordered_map<char,TrieNode*> children;
    char ch;
    int wordCount;
    int prefixCount;
    bool flag;

    public:
    TrieNode() {
        wordCount = 0;
        prefixCount = 0;
        flag = false;
    }

    void add(char ch) {
        children[ch] = new TrieNode();
        
        
    }

    void remove(char ch) {
        // cout<<"prefix count:" <<children[ch]->prefixCount<<endl;
    //    children[ch]->prefixCount--;
       

    //    if(children[ch]->prefixCount < 0) {
    //     children.erase(ch);
    //    }
    }

    bool contains(char ch) {
        return children.find(ch) != children.end();
    }

    TrieNode* get(char ch) {
        return children[ch];
    }

    void setEnd() {
        flag = true;
        // wordCount += 1;
    }

    bool isEnd() {
        return flag;
    }

    void increasePrefixCount() {
        prefixCount++;
    }


    void decreasePrefixCount() {
        prefixCount--;
    }

    void increaseWordCount() {
        wordCount++;
    }

    void decreaseWordCount() {
        wordCount--;
    }

    int getWordCount() {
        return wordCount;
    }

    int getPrefixCount() {
        return prefixCount;
    }

};

class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* temp = root;

        for (int i = 0; i < word.size(); i++) {
            if (!temp->contains(word[i])) {
                temp->add(word[i]);
            }
            temp = temp->get(word[i]);
            temp->increasePrefixCount();
        }

        temp->setEnd();
        temp->increaseWordCount();
    }
    
    int countWordsEqualTo(string word) {
        TrieNode* temp = root;
        for (int i = 0; i < word.size(); i++) {
            if(!temp->contains(word[i])) {
                return 0;
            }

            temp = temp->get(word[i]);
            
        }

        if(temp->isEnd()) {
            return temp->getWordCount();
        }

        return 0;

        
    }
    
    int countWordsStartingWith(string word) {
        TrieNode* temp = root;
        for (int i = 0; i < word.size(); i++) {
            if(!temp->contains(word[i])) {
                return 0;
            }

            temp = temp->get(word[i]);

        }
        return temp->getPrefixCount();

        
    }
    
    void erase(string word) {
        TrieNode* temp = root;
        for (int i = 0; i < word.size(); i++) {
            if (!temp->contains(word[i])) {
                break;
            }

            temp = temp->get(word[i]);
        }

        if(temp->isEnd()) {
            temp = root;

            for (int i = 0; i < word.size(); i++) {
               temp = temp->get(word[i]);
               temp->decreasePrefixCount();
            }

            temp->decreaseWordCount();
        }

        
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */