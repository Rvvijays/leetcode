class Solution {
public:
    int recursion(int index, int target, vector<int> &coins){

        if(index == 0){
            if(target % coins[index] ==0){
                return 1;
            }
            return 0;
        }


        int notTake = recursion(index-1,target,coins);
        int take = 0;
        if(target >= coins[index]){
            take = recursion(index,target - coins[index],coins);
        }
        return take + notTake;

    }
    int memorization(int index, int target, vector<int> &coins,vector<vector<int>> &dp){

        if(index == 0){

            if(target % coins[index] ==0){
                return 1;
            }
            // if(coins[index]== target){
            //     return 1;
            // }

            return 0;
        }

        // if(index<0){
        //     return 0;
        // }

        if(dp[index][target]!=-1){
            return dp[index][target];
        }


        int notTake = memorization(index-1,target,coins,dp);
        int take = 0;
        if(target >= coins[index]){
            take = memorization(index,target - coins[index],coins,dp);
        }
        return dp[index][target] = take + notTake;

    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();


        // return recursion(n-1,amount,coins);

        vector<vector<int>> dp(n,vector<int>(amount+1,-1));

        return memorization(n-1,amount,coins,dp);

        
    }
};