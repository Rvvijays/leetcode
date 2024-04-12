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
            path += recursion(m+dx[i],n+dy[i]);
        }

        return dp[m][n] = path;
    }

    int tabulation(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));

        dp[0][0] = 1;
        int dx[2] = {-1,0};
        int dy[2] = {0,-1};
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
               if(i ==0 && j==0){
                continue;
               }
               int path =0;

                for(int k=0; k<2; k++){
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if(x<0 || y <0){
                        continue;
                    }
                    path += dp[x][y];
                }

                dp[i][j] = path;
            
            }
        }

        return dp[m-1][n-1];
        
    }
    int uniquePaths(int m, int n) {
        
        // return recursion(m-1,n-1);

        // vector<vector<int>> dp(m,vector<int>(n,-1));

        // return memorization(m-1,n-1,dp);

        return tabulation(m,n);
        
    }
};