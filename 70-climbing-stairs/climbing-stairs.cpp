class Solution {
public:

    int memoization(int sum, int n, vector<int> &dp){
         if(sum == n){
            return 1;
        }

        if(sum > n){
            return 0;
        }

        if(dp[sum]!=-1){
            return dp[sum];
        }
        return dp[sum] = memoization(sum+1,n,dp) + memoization(sum+2,n,dp);
    }

    int recursion(int sum, int n){
        if(sum == n){
            return 1;
        }

        if(sum > n){
            return 0;
        }

        return  recursion(sum+1,n) + recursion(sum+2,n);
    }

    int recursion2(int n){
        if(n==0 || n==1){
            return 1;
        }

       
        return  recursion2(n-1) + recursion2(n-2);
    }

    int memoization2(int n, vector<int> &dp){
        if(n ==0 || n ==1){
            return 1;
        }

        if(dp[n]!=-1){
            return dp[n];
        }

        return dp[n] = memoization2(n-1,dp) + memoization2(n-2,dp);
    }

    int tabulation(int n){
        vector<int> dp(n+2,0);
        dp[n] = 1;
        dp[n+1] = 0;

        for(int i = n-1; i>=0; i--){
            dp[i] = dp[i+1] + dp[i+2];
        }

        return dp[0];
    }

   
    int climbStairs(int n) {

        // return recursion(0,n); TLE

        // vector<int> dp(n+1,-1);
        // return memoization(0,n,dp);

        // doing backwards.
        // return recursion2(n);
        // return memoization2(n,dp);

        // dp[0] = dp[1] = 1;

        // for(int i=2; i<=n; i++){
        //     dp[i] = dp[i-1] + dp[i-2];
        // }

        // return dp[n];


        // space optimizing
        // int prev2 = 1;
        // int prev1 = 1;

        // int curr = 0;
        // for(int i=2; i<=n; i++){
        //     curr = prev1 + prev2;
        //     prev2 = prev1;
        //     prev1 = curr;
        // }

        // return prev1;

        return tabulation(n);


        
    }
};