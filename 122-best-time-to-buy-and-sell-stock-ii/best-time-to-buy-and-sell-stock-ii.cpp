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

        // vector<omt

        vector<int> prev(2,0);

        for(int index = n-1; index>=0; index--){
            vector<int> curr(2,0);
            for(int canBuy = 0; canBuy<2; canBuy++){
                 if(canBuy == 0){
                    int buyy = -prices[index] + prev[1];
                    int notByt =prev[0];
                    curr[canBuy] =  max(buyy,notByt);
                }else{
                    int sell = prev[0] + prices[index];
                    int notSell = prev[1];

                    curr[canBuy]= max(sell, notSell);
                }
            }
            prev = curr;
        }
        return prev[0];
    }


    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        // vector<vector<int>> dp(n+1,vector<int>(2,-1));
        // return recursion(0,0,prices,dp);

        return tabulation(n,prices);
        
    }
};