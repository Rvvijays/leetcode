class Solution {
public:

    int recursion(int index, int canBuy, vector<int> &prices, vector<vector<int>> &dp){


        if(index==prices.size()){
            return 0;
        }

        if(dp[index][canBuy]!=-1){
            return dp[index][canBuy];
        }


        if(canBuy == 0){
            // i can buy or not buy.
            int buyy = -prices[index] + recursion(index+1,1,prices,dp);
            int notByt = recursion(index+1,0,prices,dp);

            return dp[index][canBuy] =  max(buyy,notByt);
        }

        int sell = recursion(index+1,0,prices,dp) + prices[index];
        int notSell = recursion(index+1,1,prices,dp);

        return dp[index][canBuy]= max(sell, notSell);
    }

    int tabulation(int n, vector<int> &prices) {
        vector<vector<int>> dp(n+1,vector<int>(2,0));

        for(int index = n-1; index>=0; index--){
            for(int canBuy = 0; canBuy<2; canBuy++){
                 if(canBuy == 0){
                    int buyy = -prices[index] + dp[index+1][1];
                    int notByt =dp[index+1][0];
                    dp[index][canBuy] =  max(buyy,notByt);
                }else{
                    int sell = dp[index+1][0] + prices[index];
                    int notSell = dp[index+1][1];

                    dp[index][canBuy]= max(sell, notSell);
                }
            }
        }
        return dp[0][0];
    }


    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        // vector<vector<int>> dp(n+1,vector<int>(2,-1));
        // return recursion(0,0,prices,dp);

        return tabulation(n,prices);
        
    }
};