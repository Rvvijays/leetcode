/*

1 3 4 5


*/

class Solution {
public:

    int recursion(int i, int j, vector<int>& cuts, vector<vector<int>> &dp) {

        if( i > j){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int minCost = 1e9;
        for(int k = i; k<=j; k++) {
            int cost = cuts[j+1] - cuts[i-1] 
            + recursion(i,k-1,cuts,dp) 
            + recursion(k+1,j,cuts,dp);

            minCost = min(cost,minCost);
        }

        return dp[i][j] = minCost;

       
    }
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();


        cuts.push_back(0);
        cuts.push_back(n);



        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(m+2,vector<int>(m+2,-1));

        return recursion(1,m, cuts,dp);

        // vector<vector<int>> dp(m,vector<int>(m+2,0));

        // for(int i = n-1; i>=0; i--) {
        //     for(int j=1; j<=m; j++) {
        //          int minCost = 1e9;
        //         for(int k = i; k<=j; k++) {
        //             int cost = cuts[j+1] - cuts[i-1] 
        //             + dp[i][k-1]
        //             + dp[k+1][j];

        //             minCost = min(cost,minCost);
        //         }

        //         dp[i][j] = minCost;
        //     }
        // }
        // return dp[1][m];
        
    }
};