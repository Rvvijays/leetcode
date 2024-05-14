class TrieNode {
    unordered_map<char,TrieNode*> children;
    char ch;
    bool end;

    public:
    TrieNode() {
        end = false;
    }

    bool contains(char ch) {
        return children.find(ch) != children.end();
    }

    void add(char ch) {
        children[ch] = new TrieNode();
    }

    TrieNode* get(char ch) {
        return children[ch];
    }

    bool isEnd() {
        return end;
    }

    char getChar() {
        return ch;
    }

    void setEnd() {
        end = true;
    }
};

class Trie {
    TrieNode* root;

    public:
    Trie() {
        root = new TrieNode();
    }


    void insert(string word) {
        TrieNode* node = root;

        for (int i = 0; i < word.size(); i++) {
            if (!node->contains(word[i])) {
                node->add(word[i]);
            }

            node = node->get(word[i]);
        }

        node->setEnd();
    }

    bool startsWith(string prefix) {
        TrieNode* node = root;

        for (int i = 0; i < prefix.size(); i++) {
            if (!node->contains(prefix[i])) {
                return false;
            }

            node = node->get(prefix[i]);
        }

        return true;
    }

    bool checkAllPrefix(string word, unordered_map<string,bool> &mp) {
        TrieNode* node = root;
        // cout<<"aa rha yha"<<endl;
        string prefix = "";
        for (int i = 0; i < word.size(); i++) {
            if (!node->contains(word[i])) {
                return false;
            }

            node = node->get(word[i]);
            prefix += word[i];
            // cout<<"prefix: "<<prefix<<endl;

            if (mp.find(prefix)==mp.end()){
                return false;
            }
        }

        // cout<<"checking :"<<prefix<<endl;

       return mp.find(prefix)!=mp.end();
    }


};

class Solution {
public:
    string longestWord(vector<string>& words) {

        Trie* tr = new Trie();

        sort(words.begin(),words.end());

        unordered_map<string,bool> mp;

        for (int i = 0; i < words.size(); i++) {
            mp[words[i]] = true;
            tr->insert(words[i]);
        }

        int maxLen = 0;
        string ans = "";

        for (int i = 0; i < words.size(); i++) {
            if(tr->checkAllPrefix(words[i], mp)) {
                if(maxLen < words[i].size()) {
                    maxLen = words[i].size();
                    ans = words[i];
                }
            }

        }

        return ans;


        
    }
};