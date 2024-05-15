class Solution {
public:

    int recursion(int i, int j, vector<int>& values, vector<vector<int>> &dp) {
        if(i+1 == j){
            return 0;
        }

        if(dp[i][j]!=-1) {
            return dp[i][j];
        }

        int mini = 1e9;

        for(int k=i+1; k<j; k++) {
            int temp = values[i] * values[k] * values[j] 
            + recursion(i,k,values,dp) 
            + recursion(k,j,values,dp);

            mini = min(temp,mini);
        }

        return dp[i][j] =  mini ;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();

       vector<vector<int>> dp(n+1, vector<int>(n+1,-1));

        return recursion(0,n-1,values,dp);
        
    }
};