class Solution {
public:

    bool recursion(int i, int j, string str1, string str2,vector<vector<int>> &dp) {


        if(i==0 && j==0){
            return true;
        }

        if(j==0 && i>0){
            return false;
        }

        if(i==0 && j>0){
            for(int k=1; k<=j; k++){
                if(str2[k-1]!='*'){
                    return false;
                }
            }

            return true;
        }




        if(dp[i][j]!=-1){
            return dp[i][j];
        }


        if(str2[j-1] == '?' || str1[i-1] == str2[j-1]){
            return dp[i][j] = recursion(i-1,j-1,str1,str2,dp);
        }else if(str2[j-1] == '*') {
            return dp[i][j] = recursion(i-1,j,str1,str2,dp) || recursion(i,j-1,str1,str2,dp);

        }

        return dp[i][j] = false;
    }


    bool tabulation(int n, int m, string str1, string str2){
        vector<vector<bool>> dp(n+1, vector<bool>(m+1,false));

        dp[0][0] = true;

       for(int i=1; i<=n; i++){
        dp[i][0] = false;
       }

       for(int j=1; j<=m; j++){

        bool fl = true;
        for(int k=1; k<=j; k++){
            if(str2[k-1] !='*'){
                fl = false;
                break;
            }
        }

        dp[0][j] = fl;
       }




        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(str2[j-1] == '?' || str1[i-1] == str2[j-1]){

                     dp[i][j] = dp[i-1][j-1];
                }else if(str2[j-1] == '*') {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];

                }
            }
        }

        return dp[n][m];
       


    }
    bool isMatch(string s, string p) {

        int n = s.size();
        int m = p.size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));


        // return recursion(n-1,m-1,s,p,dp);

        return tabulation(n,m,s,p);

        
    }
};