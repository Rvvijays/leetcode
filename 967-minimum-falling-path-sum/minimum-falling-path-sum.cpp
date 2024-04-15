class Solution {
public:

    int recursion(int i, int j, int n,vector<vector<int>>& matrix){
        if(i<0 || j<0 || i>=n || j>=n ){
            return 100;
        }

        if(i == n-1){
            return matrix[i][j];
        }

       

        int bottom = matrix[i][j] + recursion(i+1,j,n,matrix);
        int left = matrix[i][j] + recursion(i+1,j-1,n,matrix);
        int right = matrix[i][j] + recursion(i+1,j+1,n,matrix);



        return min(bottom,min(left,right));

    }


    int memorization(int i, int j, int n,vector<vector<int>>& matrix,vector<vector<int>>& dp){
        if(i<0 || j<0 || i>=n || j>=n ){
            return 1e5;
        }

        if(i == n-1){
            return matrix[i][j];
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

       

        int bottom = matrix[i][j] + memorization(i+1,j,n,matrix,dp);
        int left = matrix[i][j] + memorization(i+1,j-1,n,matrix,dp);
        int right = matrix[i][j] + memorization(i+1,j+1,n,matrix,dp);



        return dp[i][j] = min(bottom,min(left,right));

    }

    int tabulation(int i, int j, int n,vector<vector<int>>& matrix){
        vector<vector<int>> dp(n,vector<int>(n,0));

        for(int i=0; i<n; i++){
            dp[n-1][i] = matrix[n-1][i];
        }

        for(int i=n-2; i>=0; i--){
            for(int j=0; j<n; j++){
                

                int bottom = dp[i+1][j];
                int left = 1e9;
                if(j>0){
                    left = dp[i+1][j-1];
                }
                int right = 1e9;
                if(j<n-1){
                    right = dp[i+1][j+1];
                }

                 dp[i][j] = min(bottom,min(left,right)) +  matrix[i][j];

            }
        }

        int mini = INT_MAX;
        for(int i=0; i<n; i++){
            cout<<dp[0][i]<<" ";
            mini = min(mini,dp[0][i]);
        }

        return mini;

    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        int mini = INT_MAX;
        //     vector<vector<int>> dp(n,vector<int>(n,-1));

        // for(int i=0; i<n; i++){
            // mini = min(mini,recursion(0,i,n,matrix));
            // mini = min(mini,memorization(0,i,n,matrix,dp));

            // mini = min(mini,tabulation(0,i,n,matrix));
        // }


        return tabulation(0,1,n,matrix);

        
    }
};