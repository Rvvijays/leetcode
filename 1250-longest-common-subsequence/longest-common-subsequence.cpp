class Solution {
public:

    int recursion(int index1, int index2, string text1, string text2){

        if(index1<0 || index2<0){
            return 0;
        }

        int matched = INT_MIN;
        int notMatched = INT_MIN;

        if(text1[index1] == text2[index2]){
            return 1 + recursion(index1-1, index2-1,text1,text2);
        }
        return max(recursion(index1-1,index2,text1,text2), recursion(index1,index2-1,text1,text2));

    }
    int memorization(int index1, int index2, string text1, string text2,vector<vector<int>> &dp){

        if(index1==0 || index2==0){
            return 0;
        }

        if(dp[index1][index2]!=-1){
            return dp[index1][index2];
        }


        if(text1[index1-1] == text2[index2-1]){
            return dp[index1][index2] =  1 + memorization(index1-1, index2-1,text1,text2,dp);
        }
        return dp[index1][index2] = max(memorization(index1-1,index2,text1,text2,dp), memorization(index1,index2-1,text1,text2,dp));
        
    }

    int tabulation(int n1,int n2, string text1, string text2){
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));

        // if(text1[0] == text2[0]){
        //     dp[0][0] = 1;
        // }

        for(int index1 = 1; index1 <= n1; index1++){
            for(int index2 = 1; index2 <= n2; index2++){
                int matched = 0;
                int notMatched = 0;
                if(text1[index1-1] == text2[index2-1]){
                    matched = 1 + dp[index1-1][index2-1];
                }else{
                    notMatched = max(dp[index1-1][index2], dp[index1][index2-1]);
                }

                dp[index1][index2] = max(matched,notMatched);
            }
        }

        return dp[n1][n2];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        // return recursion(n1-1,n2-1,text1,text2);
        // vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        // return memorization(n1,n2,text1,text2,dp);

         return tabulation(n1,n2,text1,text2);
    }
};