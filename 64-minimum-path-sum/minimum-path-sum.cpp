class Solution {
public:
    int recursion(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<int>> &dp)  {

        if(i == n-1 && j == m-1) {
            return grid[i][j];
        }

        if(i >= n || j >= m) {
            return INT_MAX;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int right =  recursion(i,j+1,n,m,grid,dp);
        int bottom = recursion(i+1,j,n,m,grid,dp);

        return dp[i][j] = min(right,bottom) + grid[i][j];

    }
    int minPathSum(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        // vector<vector<int>> dp(n,vector<int>(m,-1));

        // return recursion(0,0,n,m,grid,dp);



        vector<vector<int>> dp(n,vector<int>(m,0));

        // dp[n-1][m-1] = grid[n-1][m-1];

        for(int i = n-1; i>=0; i--) {
            for(int j=m-1; j>=0; j--) {

                if(i == n-1 && j == m-1) {
                    dp[i][j] = grid[i][j];
                    continue;
                }

                int left = 1e9;
                if(j<m-1){
                    left = dp[i][j+1];
                }
                int right = 1e9;
                if(i<n-1){
                    right = dp[i+1][j];

                }
                dp[i][j] = min(left,right) + grid[i][j];
            }
        }

        return dp[0][0];




        
    }
};