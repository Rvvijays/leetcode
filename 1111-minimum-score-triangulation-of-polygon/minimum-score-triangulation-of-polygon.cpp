class Solution {
public:

    int recursion(int i, int j, vector<int>& values, vector<vector<int>> &dp) {
        if(i>=j){
            return 0;
        }

        if(dp[i][j]!=-1) {
            return dp[i][j];
        }

        int mini = INT_MAX;

        for(int k=i; k<j; k++) {
            int temp = values[i-1] * values[k] * values[j] + recursion(i,k,values,dp) + recursion(k+1,j,values,dp);

            mini = min(temp,mini);
        }

        return dp[i][j] = mini ;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();

       vector<vector<int>> dp(n, vector<int>(n,-1));

        return recursion(1,values.size()-1,values,dp);
        
    }
};