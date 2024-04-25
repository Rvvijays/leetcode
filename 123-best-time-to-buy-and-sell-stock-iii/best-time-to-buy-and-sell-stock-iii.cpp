class Solution {
public:

    int recursion(int index, int buy,int transaction, vector<int> &prices, vector<vector<vector<int>>> &dp){
        if(index ==prices.size() || transaction >4){
            return 0;
        }

        if(dp[index][buy][transaction]!=-1){
            return dp[index][buy][transaction];
        }


        if(buy == 0){
            // can buy
            return dp[index][buy][transaction] = max(recursion(index+1,1,transaction+1,prices,dp) - prices[index], recursion(index+1,0,transaction,prices,dp));

        }else{

            return dp[index][buy][transaction] = max(recursion(index+1,0,transaction+1,prices,dp) + prices[index], recursion(index+1,1,transaction,prices,dp));

        }
    }

    int tabulation(int n, vector<int> &prices){

        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(5,0)));


        vector<vector<int>> prev(2,vector<int>(5,0));
        for(int index=n-1; index>=0; index--){
            vector<vector<int>> curr(2,vector<int>(5,0));
            for(int buy=0; buy<2; buy++){
                for(int transaction=0; transaction<4; transaction++){
                    if(buy == 0){
                         curr[buy][transaction] = max(prev[1][transaction+1] - prices[index],
                         prev[0][transaction]);

                    }else{

                         curr[buy][transaction] = max(prev[0][transaction+1] + prices[index], 
                        prev[1][transaction]);

                    }
                }
            }
            prev = curr;
        }

        return prev[0][0];

    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        // vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(5,-1)));

        // vector<vector<int>> dp(n,vector<int>(2,-1));

        // return recursion(0,0,0,prices,dp);

        return tabulation(n,prices);
        
    }
};