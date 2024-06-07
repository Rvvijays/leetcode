class TrieNode {
    char ch;
    TrieNode* children[27];
    bool end;

    public:
    TrieNode() {
        end = false;
        for(int i=0; i<26; i++) {
            children[i] = nullptr;
        }
    }

    void add(char ch) {
        children[ch-'a'] = new TrieNode();
    }

    bool contains(char ch) {
        return children[ch-'a']!=nullptr;
    }

    TrieNode* get(char ch) {
        return children[ch-'a'];
    }

    bool isEnd() {
        return end;
    }

    void setEnd() {
        end =true;
    }

};



class Solution {

    TrieNode* root;



public:

    void insert(string word) {
        TrieNode* temp = root;

        for(int i=0; i<word.size(); i++) {
            if(!temp->contains(word[i])) {
                temp->add(word[i]);
            }

            temp = temp->get(word[i]);
        }

        temp->setEnd();
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

    string search(string word) {
        TrieNode* temp = root;

        for(int i=0; i<word.size(); i++) {
            if(!temp->contains(word[i])) {
                return word;
            }

            temp = temp->get(word[i]);

            if(temp->isEnd()) {
                return word.substr(0,i+1);
            }
        }

        return word;
    }

                     
    string brute(vector<string>& dictionary, string sentence) {
        unordered_map<string, bool> hash;

        for (int i = 0; i < dictionary.size(); i++) {
            hash[dictionary[i]] = true;
        }

        // sc: o(n)
        // tc: o(nlogn)

        string ans;

        stringstream s(sentence);
        string temp;

        while (getline(s, temp, ' ')) {
            string tt = "";
            bool found = false;
            for (int i = 0; i < temp.size(); i++) {
                tt += temp[i];

                if (hash.find(tt) != hash.end()) {
                    ans += tt + " ";
                    found = true;
                    break;
                }
            }

            if (!found) {
                ans += tt + " ";
            }
        }

        // tc : o(nm)

        ans.pop_back();

        return ans;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {

        root = new TrieNode();

        // return brute(dictionary, sentence);

        for (int i=0; i<dictionary.size(); i++) {
            insert(dictionary[i]);
        }


        stringstream s(sentence);

        string str;

        string ans;

        while(getline(s,str,' ')) {

            ans += search(str) + " ";

        }

        ans.pop_back();

        return ans;







    }
};