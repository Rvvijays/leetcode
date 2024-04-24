class Solution {
public:

    int recursion(int index1, int index2, string large, string small){

        if(index2==0){
            return 1;
        }

        if(index1==0){
            return 0;
        }



        // matched
        if(large[index1-1] == small[index2-1]){
            return recursion(index1-1,index2-1,large,small) + recursion(index1-1,index2,large,small);

        }else{
            return recursion(index1-1,index2,large,small);
        }
        // not matched

    }

    int memorization(int index1, int index2, string large, string small,vector<vector<int>> &dp){

        if(index2==0){
            return 1;
        }

        if(index1==0){
            return 0;
        }


    if(dp[index1][index2]!=-1){
        return dp[index1][index2];
    }

        // matched
        if(large[index1-1] == small[index2-1]){
            return dp[index1][index2]= memorization(index1-1,index2-1,large,small,dp) + memorization(index1-1,index2,large,small,dp);

        }
            return dp[index1][index2] = memorization(index1-1,index2,large,small,dp);
        
        // not matched

    }

    int tabulation(int n, int m, string large, string small){
        vector<vector<double>> dp(n+1,vector<double>(m+1,0));

        for(int index1=0; index1<=n; index1++){
            dp[index1][0] = 1;
        }

        for(int index2=1; index2<=m; index2++){
            dp[0][index2] = 0;
        }

        for(int index1=1; index1<=n; index1++){
            for(int index2=1; index2<=m; index2++){
                if(large[index1-1] == small[index2-1]){
                    dp[index1][index2] = dp[index1-1][index2-1] + dp[index1-1][index2];
                }else{
                    dp[index1][index2] = dp[index1-1][index2];
                }
            }

        }

        return (int)dp[n][m];
    }
    int numDistinct(string s, string t) {

        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

        // return recursion(n,m,s,t);

        // return memorization(n,m,s,t,dp);

        return tabulation(n,m,s,t);

        
    }
};