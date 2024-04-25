class Solution {
public:

    int recursion(int index, int buy, int fee, vector<int> &prices,vector<vector<int>> &dp){
        if(index == prices.size()){
            return 0;
        }

        if(dp[index][buy]!=-1){
            return dp[index][buy];
        }

        int profit = 0;

        if(buy == 0){
            profit = max(recursion(index+1,1,fee,prices,dp) - prices[index],
            recursion(index+1,0,fee,prices,dp));
        }else{

            profit = max(recursion(index+1,0,fee,prices,dp) + prices[index] - fee,
            recursion(index+1,1,fee,prices,dp));

        }

        return dp[index][buy] = profit;
    }

    int tabulation(int n, int fee, vector<int> &prices){
        vector<vector<int>> dp(n+1,vector<int>(2,0));

        for(int index=n-1; index>=0; index--){
            for(int buy=0; buy<2; buy++){

                int profit = 0;

                if(buy == 0){
                    profit = max(dp[index+1][1] - prices[index],
                    dp[index+1][0]);
                }else{

                    profit = max(dp[index+1][0] + prices[index] - fee,
                    dp[index+1][1]);

                }

                 dp[index][buy] = profit;
            }
        }

        return dp[0][0];

    }

    int maxProfit(vector<int>& prices, int fee) {

        int n = prices.size();

        // vector<vector<int>> dp(n,vector<int>(2,-1));

        // return recursion(0,0,fee,prices,dp);
        return tabulation(n,fee,prices);

        
    }
};