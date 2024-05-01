class Solution {
public:

    int recursion(int index, vector<int> &cost, vector<int> &dp){
      

        if(index >= cost.size()){
            return 0;
        }

        if(dp[index]!=-1){
            return dp[index];
        }
        
        return dp[index] =cost[index] +   min(recursion(index+1,cost,dp),recursion(index+2,cost,dp));

    
    }

    int tabulation(vector<int>& cost){
        int n = cost.size();
        vector<int> dp(n+2,0);

        for(int index=n-1; index>=0; index--){

            dp[index] = cost[index] +   min(dp[index+1],dp[index+2]);
        }

        return min(dp[0], dp[1]);



    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // vector<
        // vector<int> dp(n,-1);
        // return min(recursion(0, cost,dp), recursion(1,cost,dp));

        return tabulation(cost);
    }
};