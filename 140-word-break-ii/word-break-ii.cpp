class Solution {
public:

    void generate(int index,string s,vector<string> &currline, unordered_map<string,bool> &words, vector<vector<string>> &ans) {

        if(index == s.length()) {
            ans.push_back(currline);
            return;
        }


        string curr;
        for(int i=index; i<s.length(); i++) {
            curr += s[i];
            // cout<<"word: "<<curr<<endl;
            if(words.find(curr) != words.end()) {
                // cout<<"found word: "<<curr<<endl;
                currline.push_back(curr);
                generate(i+1,s,currline,words,ans);
                currline.pop_back();
                // break;
            }


            // curr.pop_back();
        }

        // generate(index+1,s,currline,words,ans);


    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {

        vector<vector<string>> ans;
        unordered_map<string,bool> words;

        for (int i = 0; i < wordDict.size(); i++) {
            words[wordDict[i]] = true;
        }
        vector<string> curr;
        generate(0,s,curr,words,ans);

        vector<string> result;

        for (auto &v : ans) {
            string line = "";
            for(auto &w : v) {
                line += w + " ";
            }
            line.pop_back();
            result.push_back(line);
        }

        return result;
        
    }
};