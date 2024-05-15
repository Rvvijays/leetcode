class Solution {
public:
    int recursion(int i, int j, vector<int>& values, vector<vector<int>>& dp) {
        if (i + 1 == j) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int mini = 1e9;

        for (int k = i + 1; k < j; k++) {
            int temp = values[i] * values[k] * values[j] +
                       recursion(i, k, values, dp) +
                       recursion(k, j, values, dp);

            mini = min(temp, mini);
        }

        return dp[i][j] = mini;
    }

    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();

        //    vector<vector<int>> dp(n+1, vector<int>(n+1,-1));

        //     return recursion(0,n-1,values,dp);

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = n - 1; i>=0; i--) {
            for (int j = i + 2; j<n; j++) {
                int mini = 1e9;

                for (int k = i + 1; k < j; k++) {
                    int temp = values[i] * values[k] * values[j] +
                            dp[i][k] + dp[k][j];
                            

                    mini = min(temp, mini);
                }

                 dp[i][j] = mini;
            }
        }

        return dp[0][n-1];


    }
};