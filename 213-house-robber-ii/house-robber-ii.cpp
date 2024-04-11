class Solution {
public:

    int recursion(int start, int index, vector<int> &nums) {

        if(index == start){
            return nums[index];
        }

        if(index < start ){
            return 0;
        }
        int take = nums[index] + recursion(start, index - 2,nums);
       
        int notTake = 0 + recursion(start,index - 1,nums);

        return max(take, notTake);
    }

    int memorization(int start, int index, vector<int> &nums,vector<int> &dp) {

        if(index == start){
            return nums[index];
        }

        if(index < start ){
            return 0;
        }

        if(dp[index]!=-1){
            return dp[index];
        }
        int take = nums[index] + memorization(start, index - 2,nums,dp);
       
        int notTake = 0 + memorization(start,index - 1,nums,dp);

        return dp[index] = max(take, notTake);
    }

    int tabulation(int start, int end, vector<int> &nums){
        
        vector<int> dp(end+1,0);
        dp[start] = nums[start];

        for(int i=start+1; i<=end; i++){
            int nonTake = dp[i-1];
            int take = nums[i];
            if(i>1){
                take += dp[i-2];
            }

            dp[i] = max(take,nonTake);
        }

        return dp[end];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n<2){
            return nums[0];
        }
        // return max(recursion(0,n-2,nums),recursion(1,n-1,nums));

        // vector<int> dp1(n+1,-1);
        // vector<int> dp2(n+1,-1);
        // return max(memorization(0,n-2,nums,dp1),memorization(1,n-1,nums,dp2));



        return max(tabulation(0,n-2,nums),tabulation(1,n-1,nums));
    }
};