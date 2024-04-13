class Solution {
public:
    int recursion(int i,int j, vector<vector<int>>& triangle){
        if(i == 0 && j == 0){
            return triangle[0][0];
        }

        if(i<0 || j<0 || j > i ){
            return 1e5;
        }




        int top = recursion(i-1,j,triangle);
        int left = recursion(i-1,j-1,triangle);

        return min(top,left) + triangle[i][j];
    }

    int memorization(int i,int j, vector<vector<int>>& triangle,vector<vector<int>>& dp){
        if(i == 0 && j == 0){
            return triangle[0][0];
        }

        if(i<0 || j<0 || j > i ){
            return 1e5;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }




        int top = memorization(i-1,j,triangle,dp);
        int left = memorization(i-1,j-1,triangle,dp);

        return dp[i][j] =  min(top,left) + triangle[i][j];
    }


    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();
        int mini = 1e5;
        for(int i=0; i<n; i++){
            // mini = min(mini, recursion(n-1,i,triangle));
            vector<vector<int>> dp(n,vector<int>(n,-1));
            mini = min(mini, memorization(n-1,i,triangle,dp));
        }

        return  mini;
        
    }
};