class Solution {
public:

    int recursion(int m, int n){
        if(m == 0 && n == 0){
            return 1;
        }

        if(m<0 || n<0){
            return 0;
        }

        int left = recursion(m-1,n);
        int top = recursion(m,n-1);

        return left + top;
    }

    int memorization(int m, int n, vector<vector<int>> &dp){
         if(m == 0 && n == 0){
            return 1;
        }

        if(m<0 || n<0){
            return 0;
        }

        if(dp[m][n]!=-1){
            return dp[m][n];
        }

        int dx[2] = {-1,0};
        int dy[2] = {0,-1};

        int path = 0;

        for(int i=0; i<2; i++){
            path += memorization(m+dx[i],n+dy[i],dp);
        }

        return dp[m][n] = path;
    }

    int tabulation(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));

        dp[0][0] = 1;
     
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
               if(i ==0 && j==0){
                continue;
               }
               int path =0;

                if(i >0){
                    path += dp[i-1][j];
                }

                if(j>0){
                    path += dp[i][j-1];
                }

                dp[i][j] = path;
            
            }
        }

        return dp[m-1][n-1];
        
    }

    int spaceoptimization(int m, int n){
        vector<vector<int>> dp(m,vector<int>(n,0));

        vector<int> prev(n,0);

        // prev[0] = 1;
     
        for(int i=0; i<m; i++){


            vector<int> temp(n,0);

            for(int j=0; j<n; j++){
               if(i ==0 && j==0){
                temp[0] = 1;
                continue;
               }
               int path = 0;

                if(i > 0){
                    path += prev[j];
                }

                if(j > 0){
                    path += temp[j-1];
                }

                temp[j] = path;
            
            }
            prev = temp;
        }

        return prev[n-1];
    }
    int uniquePaths(int m, int n) {
        
        // return recursion(m-1,n-1);

        vector<vector<int>> dp(m,vector<int>(n,-1));

        // return tabulation(m-1,n-1,dp);
            return spaceoptimization(m,n);
        // return spaceoptimization(m,n);
        
    }
};