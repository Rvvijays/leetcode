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


    int tabulation(int n, int amount, vector<int> &coins){

        vector<vector<int>> dp(n,vector<int>(amount+1,1e9));

        for(int i=0; i<=amount; i++){
            if(i % coins[0]==0){
                dp[0][i] = i / coins[0];
            }
        }

        for(int index=1; index<n; index++){
            for(int target=0; target<=amount; target++){
                int notTake = dp[index-1][target];

                int take = 1e9;

                if(target >= coins[index]){
                    take = 1 + dp[index][target - coins[index]];
                }

                dp[index][target] =  min(take,notTake);
            }
        }

        return dp[n-1][amount];

      
    }

     int spaceoptimization(int n, int amount, vector<int> &coins){

        // vector<vector<int>> dp(n,vector<int>(amount+1,1e9));
        vector<int> prev(amount+1,1e9);

        for(int i=0; i<=amount; i++){
            if(i % coins[0]==0){
                prev[i] = i / coins[0];
            }
        }

        for(int index=1; index<n; index++){
            vector<int> curr(amount+1,1e9);
            for(int target=0; target<=amount; target++){
                int notTake = prev[target];

                int take = 1e9;

                if(target >= coins[index]){
                    take = 1 + curr[target - coins[index]];
                }

                curr[target] =  min(take,notTake);
            }
            prev =curr;
        }

        return prev[amount];

      
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        // int count =  recursion(n-1,amount,coins);

        // vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        // int count =  memorization(n-1,amount,coins,dp);

        int count =  spaceoptimization(n,amount,coins);

        return count >= 1e9 ? -1 : count;

        
    }
};