class Solution {
public:

    int recursion(int i, int j, vector<vector<int>>& grid) {
        if(i == 0 && j == 0){
            return 1;
        }

        if(i <0 || j <0){
            return 0;
        }

        if(grid[i][j]==1){
            return 0;
        }

        int left = recursion(i-1,j,grid);
        int top = recursion(i,j-1,grid);
        return left + top;
    }

     int memorization(int i, int j, vector<vector<int>>& grid,vector<vector<int>>& dp) {
        if(i == 0 && j == 0){
            return 1;
        }

        if(i <0 || j <0){
            return 0;
        }

        if(grid[i][j]==1){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int left = memorization(i-1,j,grid,dp);
        int top = memorization(i,j-1,grid,dp);
        return dp[i][j]= left + top;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {

         if(grid[0][0]==1){
            return 0;
        }
        int n = grid.size();
        int m = grid[0].size();
        

        // return recursion(n-1,m-1,grid);
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return memorization(n-1,m-1,grid,dp);
    }
};