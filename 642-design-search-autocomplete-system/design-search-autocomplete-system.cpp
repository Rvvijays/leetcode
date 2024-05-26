class TrieNode {
    bool isWord;
        unordered_map<char,TrieNode*> children;
string word;
    int count;

    public:

    TrieNode() {
        isWord = false;
        count = 0;
    }

    void add(char ch) {
        children[ch] = new TrieNode();
    }

    bool contains(char ch) {
        return children.find(ch)!=children.end();
    }

    TrieNode* get(char ch) {
        return children[ch];
    }

    int getCount() {
        return count;
    }

    string getWord() {
        return word;
    }

    void setEnd(string sentence,int counta) {
        isWord = true;
        word = sentence;
        count += counta;
        // cout<<"ended word with: "<<
    }

    bool isEnd() {
        return isWord;
    }

    unordered_map<char,TrieNode*> getChildrens() {
        // cout<<"returning children for word:"<<word<<endl;
        return children;
        
    }

    
};

class Trie {
    TrieNode* root;
    public:
    Trie() {
        root = new TrieNode();
    }

    struct comp {
        bool operator()(pair<int,string>& a, pair<int,string>& b){
            if(a.first == b.first){
                return a.second < b.second;
            }
               return a.first > b.first;
            
        }
    };


    priority_queue<pair<int,string>, vector<pair<int,string>>, comp> pq;

    void insert(string word, int count) {

        TrieNode* temp = root;

        for(int i=0; i<word.length(); i++) {
            if(!temp->contains(word[i])) {
                temp->add(word[i]);
            }

            temp = temp->get(word[i]);
        }
        temp->setEnd(word, count);

        // cout<<"word added: "<<word<<" with count: "<<count<<endl;
    }

    bool search(string word) {
        TrieNode* temp = root;
        for(int i=0; i<word.size(); i++) {
            if(!temp->contains(word[i])) {
                return false;
            }

            temp = temp->get(word[i]);
        }

        return temp->isEnd();
    }

    bool startsWith(string word) {
        TrieNode* temp = root;
        for(int i=0; i<word.size(); i++) {
            if(!temp->contains(word[i])) {
                return false;
            }

            temp = temp->get(word[i]);
        }
        return true;
    }

    void dfs(TrieNode* temp) {
        if(temp->isEnd()) {
            // cout<<"word ffoudn: "<< temp->getWord()<<" with count: "<<temp->getCount()<<endl;
            pq.push({temp->getCount(), temp->getWord()});

            if(pq.size() > 3) {
                pq.pop();
            }
            // return;
        }

        for(auto child : temp->getChildrens()) {
            dfs(child.second);
        }
    }

    


    vector<string> getAllSentences(string prefix) {
        TrieNode* temp = root;
        vector<string> ans;
        for(int i=0; i<prefix.length(); i++) {
            if(!temp->contains(prefix[i])) {
                return ans;
            }
            temp = temp->get(prefix[i]);
        }

        // vector<pair<int,string>> words;

        // cout<<"prefix found doing dfs"<<endl;


        dfs(temp);

        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());

        

        return ans;

    }
    
};


class AutocompleteSystem {
    Trie* trie;
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        trie = new Trie();

        for(int i=0; i<sentences.size(); i++) {
            trie->insert(sentences[i],times[i]);
        }
    }

    string prefix;

    
    vector<string> input(char c) {

        vector<string> ans;

        if(c == '#') {
            trie->insert(prefix,1);
            prefix = "";
            return ans;
        }

        prefix += c;

        // cout<<"searching prefix: "<<prefix<<endl;

        // cout<<" is present: "<<trie->startsWith(prefix)<<endl;



        ans = trie->getAllSentences(prefix);     
        return ans;   
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */