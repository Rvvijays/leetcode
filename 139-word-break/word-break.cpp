class Solution {
public:

    bool check(int index, string s, vector<string> &wordDict, vector<int> &dp) {
        if(index == s.size()){
            return true;
        }

        if(dp[index]!=-1) {
            return dp[index];
        }

        for(int i=0; i<wordDict.size(); i++) {
            if(s.substr(index,wordDict[i].size()) == wordDict[i]) {

                bool matched = check(index+wordDict[i].size(),s,wordDict,dp);
                if(matched) {
                    return dp[index] = matched;
                }
            }
        }

        return dp[index] = false;


    }



    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();

        // vector<int> dp(n,-1);

    //    return check(0,s,wordDict,dp);

        vector<bool> dp(n+1,false);
        dp[n] = true;

        for(int index = n-1; index>=0; index--) {

            for(int i=0; i<wordDict.size(); i++) {
               

                if(s.substr(index,wordDict[i].size()) == wordDict[i]) {

                    if(dp[index + wordDict[i].size()]){
                        dp[index] = true;
                        break;
                    }
                    
                }
            }
        }

        return dp[0];

        
    }
};