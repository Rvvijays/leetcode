class Solution {
public:

    int recursion(int index,int curr, vector<int> &nums,vector<vector<int>> &dp) {

        if(index==nums.size()){
            return 0;
        }


        if(dp[index][curr]!=-1){
            return dp[index][curr];
        }



        // take
        if(curr == nums.size() || nums[index]>nums[curr]){
            return dp[index][curr]= max(1 + recursion(index+1,index,nums,dp),recursion(index+1,curr,nums,dp));
        }

        return dp[index][curr]= recursion(index+1,curr,nums,dp);

    }
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();


        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

        return recursion(0,n,nums,dp);
        
    }
};