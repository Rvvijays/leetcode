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
        }
    }

    vector<string> backtracking(string s, vector<string>& wordDict) {
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

    void recursion(int index, string s,string currstr, unordered_set<string> &words, vector<string> &ans) {

        if(index == s.length()) {
            currstr.pop_back();
            ans.push_back(currstr);
            return;
        }

        string curr = "";
        for(int i = index; i<s.size(); i++) {
            curr += s[i];

            if(words.find(curr) != words.end()) {
                recursion(i+1,s,currstr+curr+" ", words, ans);
            }
        }

        
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string> words(wordDict.begin(),wordDict.end());
        vector<string> ans;

         recursion(0,s,"",words,ans);

        return ans;

        
        
    }
};