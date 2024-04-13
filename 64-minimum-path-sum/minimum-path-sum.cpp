class Solution {
public:

    int recursion(int i, int j, vector<vector<int>>& grid){
        if(i ==0 && j == 0){
            return grid[i][j];
        }

        if(i<0 || j<0){
            return INT_MAX;
        }

        int left  = recursion(i-1,j,grid);
        int right = recursion(i,j-1,grid);

        return min(left,right)+grid[i][j];
       
    }
    int memorization(int i, int j, vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(i ==0 && j == 0){
            return grid[i][j];
        }

        if(i<0 || j<0){
            return INT_MAX;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int left  = memorization(i-1,j,grid,dp);
        int right = memorization(i,j-1,grid,dp);

        return dp[i][j] = min(left,right)+grid[i][j];
       
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        

        // return recursion(n-1,m-1,grid);

        vector<vector<int>> dp(n,vector<int>(m,-1));
        return memorization(n-1,m-1,grid,dp);


        
    }
};