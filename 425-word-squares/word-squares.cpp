class Solution {
public:

    vector<string> startWith(string search, vector<string> &words){
        vector<string> ans;
        for(auto word : words){

            bool found = true;
            for(int i=0; i<search.size(); i++){
                if(search[i] != word[i]){
                    found = false;
                    break;
                }
            }

            if(found){
                ans.push_back(word);
            }

        }

        return ans;
    }

    
    void recursion(int row, vector<string> &currList,vector<string> &words,unordered_map<string,vector<string>> &mp,
     vector<vector<string>> &ans){

        if(row == words[0].size()){
            ans.push_back(currList);
            return;
        }

        string prefix = "";
        for(int i=0; i<row; i++){
            prefix += currList[i][row];
        }

        vector<string> availableWords = mp[prefix];

        for(auto word : availableWords){
            currList.push_back(word);
            recursion(row+1,currList,words,mp,ans);
            currList.pop_back();
        }
    }
    vector<vector<string>> wordSquares(vector<string>& words) {


        vector<vector<string>> ans;

        unordered_map<string,vector<string>> mp;

        for(auto word : words){
            string s ="";
            for(auto c : word){
                s += c;
                mp[s].push_back(word);
            }
        }


        for(auto word : words){
            vector<string> currList;
            currList.push_back(word);
            // cout<<"start word:"<<word<<endl;
            recursion(1,currList,words,mp,ans);
            
        }

        return ans;
        
    }
};