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
            return 0;
        }


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

    int tabulation(int n, int amount, vector<int> &coins){

        vector<vector<int>> dp(n, vector<int>(amount+1,0));

        for(int i=0; i<=amount; i++){
            if(i % coins[0] == 0){
                dp[0][i] = 1;
            }
        }

        for(int index = 1; index<n; index++){
            for(int target = 0; target <= amount; target++){
                int notTake = dp[index-1][target];
                int take = 0;
                if(target >= coins[index]){
                    take = dp[index][target - coins[index]];
                }
                 dp[index][target] = take + notTake;
            }
        }

        return dp[n-1][amount];

    }

    int spaceoptimization(int n, int amount, vector<int> &coins){

        vector<int> prev(amount+1,0);

        for(int i=0; i<=amount; i++){
            if(i % coins[0] == 0){
                prev[i] = 1;
            }
        }

        for(int index = 1; index<n; index++){
            vector<int> curr(amount+1,0);

            for(int target = 0; target <= amount; target++){
                int notTake = prev[target];
                int take = 0;
                if(target >= coins[index]){
                    take = curr[target - coins[index]];
                }
                 curr[target] = take + notTake;
            }

            prev = curr;
        }

        return prev[amount];

    }



    int change(int amount, vector<int>& coins) {
        int n = coins.size();


        // return recursion(n-1,amount,coins);

        // vector<vector<int>> dp(n,vector<int>(amount+1,-1));

        // return memorization(n-1,amount,coins,dp);


        return spaceoptimization(n,amount,coins);



        
    }
};