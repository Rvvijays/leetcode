class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_map<string,bool> words;

        for(auto it: wordList) {
            words[it] = true;
        }

        queue<pair<string,int>> q;

        q.push({beginWord,1});

        while(!q.empty()){
            string word = q.front().first;
            int step = q.front().second;

            if(word == endWord){
                return step;
            }
            q.pop();

            for(int i=0; i<word.size(); i++){
                string temp = word;
                for(char ch = 'a'; ch<='z'; ch++){
                    temp[i] = ch;

                    if(words[temp]==true){
                        q.push({temp,step+1});
                        words[temp] = false;
                    }

                }

            }
            

        }

        return 0;

        
        
    }
};