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


    int recursion2(int i, int j,int n, vector<vector<int>>& triangle){

        if(i <0 || j <0 || j>i){
            return 1e5;
        }

        if(i==n-1) {
            return triangle[i][j];
        }

        int bottom = recursion2(i+1,j,n,triangle);
        int bottomright = recursion2(i+1,j+1,n,triangle);

        return min(bottom,bottomright) + triangle[i][j];
        

    }

    int memorization2(int i, int j,int n, vector<vector<int>>& triangle, vector<vector<int>>&  dp){

        if(i <0 || j <0 || j>i){
            return 1e5;
        }

        if(i==n-1) {
            return triangle[i][j];
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int bottom = memorization2(i+1,j,n,triangle,dp);
        int bottomright = memorization2(i+1,j+1,n,triangle,dp);

        return dp[i][j] =  min(bottom,bottomright) + triangle[i][j];
        

    }

    int tabulation(int n, vector<vector<int>>& triangle){
        vector<vector<int>>  dp(n,vector<int>(n,0));

        for(int j=0; j<n; j++){
            dp[n-1][j] = triangle[n-1][j];
        }

        for(int i=n-2; i>=0; i--){
            for(int j=i; j>=0; j--){
                int bottom = dp[i+1][j];
                int bottomright = dp[i+1][j+1];
                 dp[i][j] =  min(bottom,bottomright) + triangle[i][j];
            }
        }

        return dp[0][0];

    }

     int spaceoptimization(int n, vector<vector<int>>& triangle){
        // vector<vector<int>>  dp(n,vector<int>(n,0));

        vector<int> prev(n,0);

        for(int j=0; j<n; j++){
           prev[j] = triangle[n-1][j];
        }

        for(int i=n-2; i>=0; i--){
            vector<int> curr(n,0);
            for(int j=i; j>=0; j--){
                int bottom = prev[j];
                int bottomright = prev[j+1];
                 curr[j] =  min(bottom,bottomright) + triangle[i][j];
            }
            prev = curr;
        }

        return prev[0];

    }


    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();
        // int mini = 1e5;
        // for(int i=0; i<n; i++){
            // mini = min(mini, recursion(n-1,i,triangle));
            // vector<vector<int>> dp(n,vector<int>(n,-1));
            // mini = min(mini, memorization(n-1,i,triangle,dp));

        // }
        // return  mini;

        // we know source if fixed, destination point can be any thing in the row.
        // so we start from starting. means. 0,0
        // return recursion2(0,0,n,triangle);
        // vector<vector<int>> dp(n,vector<int>(n,-1));
        // return memorization2(0,0,n,triangle,dp);

        // return tabulation(n,triangle);
        return spaceoptimization(n,triangle);



       
       

        
        
    }
};