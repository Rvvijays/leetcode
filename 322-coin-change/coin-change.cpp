class Solution {
public:

    int recursion(int index, int amount, vector<int> &coins, vector<vector<int>> &dp) {

        if(index == coins.size()-1) {
            if(amount == 0) {
                return 0;
            }

            if(amount % coins[index]==0){
                return amount/coins[index];
            }

            return 1e9;
        }

        if(dp[index][amount]!=-1) {
            return dp[index][amount];
        }
        
        int take = 1e9;
        if(amount >= coins[index]) {
            take = 1 + recursion(index,amount - coins[index], coins,dp);
        }

        int nottake = recursion(index+1, amount, coins,dp);

        return dp[index][amount] = min(take,nottake);
    }
    int coinChange(vector<int>& coins, int target) {

        int n = coins.size();
        // vector<vector<int>> dp(n, vector<int>(amount+1,-1));

        // int ans = recursion(0, amount, coins,dp);

        // return ans ==1e9 ? -1 : ans;
        vector<vector<int>> dp(n, vector<int>(target+1,1e9));

        for(int amount = 0; amount <= target; amount++) {
            if(amount == 0) {
                 dp[n-1][amount] = 0;
            }

            if(amount % coins[n-1]==0){
                dp[n-1][amount] =amount/coins[n-1];
            }
        }


        for(int index = n-2; index>=0; index--) {
            for(int amount = 0; amount<= target; amount++) {
                int take = 1e9;
                if(amount >= coins[index]) {
                    take = 1 + dp[index][amount - coins[index]];
                }

                int nottake = dp[index+1][amount];

                dp[index][amount] = min(take,nottake);
            }
        }

        return dp[0][target]==1e9?-1:dp[0][target];
        
    }
};