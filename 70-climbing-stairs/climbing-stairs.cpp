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
    int climbStairs(int n) {

        // return recursion(0,n); TLE

        vector<int> dp(n,-1);
        return memoization(0,n,dp);
        
    }
};