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
class Solution {
public:
    
    bool search(int i,int j,int n, int m, int index, string word, vector<vector<char>>& board, vector<vector<int>> &vis){

        if(board[i][j]!=word[index]){
            return false;
        }
    
        if(index == word.length()-1){
            return true;
        }
        
        vis[i][j] = 1;
        
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        
        for(int k=0; k<4; k++){
            int x = i + dx[k];
            int y = j + dy[k];
            
            if(x<0 || y<0 || x >= n || y >= m || vis[x][y]==1){
                continue;
            }
                        
            if(search(x,y,n,m,index+1,word,board,vis)){
                return true;
            }   
        }
        vis[i][j] = 0;

        return false;
    }

    vector<string> brute(vector<vector<char>>& board, vector<string>& words) {
int n = board.size();
        int m = board[0].size();
        
        vector<string> ans;
        
        unordered_map<string,int> mp;





        for(auto word : words){
            
            if(mp.find(word)!=mp.end()){
                continue;
            }
            
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(board[i][j] == word[0] && mp.find(word) == mp.end()){
                        vector<vector<int>> vis(n,vector<int>(m,0));
                        cout<<"searching word:"<<word<<endl;
                        if(search(i,j,n,m,0,word,board,vis)){
                            ans.push_back(word);
                            mp[word] = 1;
                            
                        }
                    }
                }
                
              
            }
            
            cout<<"added in map:"<<word<<endl;
            
            mp[word] = 1;
            
        }
        
        return ans;
    }

    void generate(int i, int j,int n, int m,string word,vector<vector<char>>& boards, Trie* prefix,vector<vector<int>> &vis, set<string> &ans){



        if(!prefix->startsWith(word)){
            return;
        }else{
           if(prefix->search(word)){
                ans.insert(word);
                // return;
           }
        }

        vis[i][j] = 1;

        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};

        for(int k=0; k<4; k++){
            int x = i + dx[k];
            int y = j + dy[k];

            if(x<0 || y <0 || x >= n || y >= m || vis[x][y]==1){
                continue;
            }

            generate(x,y,n,m,word+boards[x][y],boards,prefix,vis,ans);


        }

        vis[i][j] = 0;

    }

    vector<string> findWords(vector<vector<char>>& boards, vector<string>& words) {
        
        Trie* prefix = new Trie();
        for(auto word : words){
            prefix->insert(word);
        }

        int n = boards.size();
        int m = boards[0].size();

        set<string> ans;
        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                string word = "";
                word += boards[i][j];
                if(ans.size() == words.size()){
                    break;
                }
                generate(i,j,n,m,word,boards,prefix,vis,ans);
            }
        }

        vector<string> found;

        for(auto it : ans){
            found.push_back(it);
        }

        return found;

        
        
    }
};