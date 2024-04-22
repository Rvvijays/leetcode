class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

    //     int maxi = 0;

    //    for(int i = 0; i<n; i++){
    //     for(int j=i+1; j<n; j++){
    //         if(prices[i] < prices[j]){
    //             maxi = max(maxi, prices[j]-prices[i]);
    //         }
    //     }
    //    }

    //    return maxi;

        int curr_min = prices[0];
        int maxi = 0;

        for(int i=1; i<n; i++){
            if(prices[i]<curr_min){
                curr_min = prices[i];
            }else{
                maxi = max(maxi,prices[i]-curr_min);
            }
        }

        return maxi;
        
    }
};