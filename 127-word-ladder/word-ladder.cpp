class Solution {
public:

    int isValid(string s1, string s2) {
        if(s1.length()!=s2.length()){
            return false;
        }

        int diff = 0;
        for(int i=0; i<s1.length(); i++) {
            if(s1[i]!=s2[i]){
                diff++;
            }

            if(diff > 1) {
                return false;
            }
        }

        return true;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

    //    unordered_map<string,bool> words;
        
    //     for(auto word: wordList){
    //         words[word] = true;
    //     }
        
        
        queue<pair<string,int>> q;
        unordered_map<string,bool> vis;
        
        q.push({beginWord,1});
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            string word = it.first;
            int level = it.second;
            
            if(word == endWord){
                return level;
            }
            
            for(int i=0; i<wordList.size(); i++){

                if(vis.find(wordList[i]) == vis.end() && isValid(word,wordList[i])) {
                    cout<<"checking ..";
                    q.push({wordList[i],level+1});
                    vis[wordList[i]] = true;
                }
                
                // char temp = word[i];
                // for(char c = 'a'; c<='z'; c++){
                //     word[i] = c;
                //     if(words[word]){
                       
                //         words[word] = false;
                //     }
                // }
                // word[i] = temp;
            }
            
        }
        
        return 0;
        
    }
};