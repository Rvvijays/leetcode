class Solution {
public:
    int minDistance(string word1, string word2) {

        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1));

        for(int index1 =1; index1<=n; index1++){
            for(int index2=1; index2<=m; index2++){
                if(word1[index1-1] == word2[index2-1]){
                    dp[index1][index2] = 1 + dp[index1-1][index2-1];
                }else{
                    dp[index1][index2] = max(dp[index1-1][index2],dp[index1][index2-1]);
                }
            }
        }

        return (n+m) - (2*dp[n][m]);

        
    }
};