class Solution {
public:

    int recursion(int index,int buy, int cooldown, vector<int>&prices,vector<vector<vector<int>>> &dp){

        if(index==prices.size()){
            return 0;
        }

        if(dp[index][buy][cooldown]!=-1){
            return dp[index][buy][cooldown];
        }

        int profit = 0;

        if(buy == 0){
            //can buy

            if(cooldown == 0){
                profit = max(recursion(index+1,1,0,prices,dp) - prices[index], recursion(index+1,0,0,prices,dp));
            }else{
                profit = recursion(index+1,0,0,prices,dp);
            }
            

        }else{

          
                profit = max(recursion(index+1,0,1,prices,dp) + prices[index],recursion(index+1,1,0,prices,dp));

            


        }

        return dp[index][buy][cooldown] = profit;

    }
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(2,-1)));

        return recursion(0,0,0,prices,dp);
        
    }
};