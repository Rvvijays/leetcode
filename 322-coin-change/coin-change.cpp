class Solution {
public:
    int recursion(int index, int target, vector<int> &coins){
        if(index == 0){
            if(target % coins[index] == 0){
                return target / coins[index];
            }

            return 1e9;
        }

        int notTake = recursion(index-1,target,coins);

        int take = 1e9;

        if(target >= coins[index]){
            take = 1 + recursion(index,target - coins[index], coins);
        }

        return min(take,notTake);
    }

    int memorization(int index, int target, vector<int> &coins, vector<vector<int>> &dp){
        if(index == 0){
            if(target % coins[index] == 0){
                return target / coins[index];
            }

            return 1e9;
        }

        if(dp[index][target]!=-1){
            return dp[index][target];
        }

        int notTake = memorization(index-1,target,coins,dp);

        int take = 1e9;

        if(target >= coins[index]){
            take = 1 + memorization(index,target - coins[index], coins,dp);
        }

        return dp[index][target] =  min(take,notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        // int count =  recursion(n-1,amount,coins);

        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int count =  memorization(n-1,amount,coins,dp);

        return count >= 1e9 ? -1 : count;

        
    }
};