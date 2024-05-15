class Solution {
public:

    bool recursion(int index, int target, vector<int>& nums,vector<vector<int>> &dp) {

        if(index == nums.size()-1) {
            if(target == 0 || nums[index] == target) {
                return true;
            }

            return false;
        }

        if(target == 0) {
            return true;
        }

        if(dp[index][target]!=-1) {
            return dp[index][target];
        }

        int take = false;
        if(target >= nums[index]) {
            take = recursion(index+1,target - nums[index], nums, dp);
        }

        bool nottake = recursion(index+1, target, nums, dp);

        return dp[index][target] = take || nottake;

    }
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;

        int n = nums.size();

        for(int i=0; i<n; i++) {
            totalSum += nums[i];
        }

        if(totalSum%2 !=0){
            return false;
        }

        int sum = totalSum/2;

        // vector<vector<int>> dp(n,vector<int>(target+1,-1));

        // return recursion(0,target,nums,dp);


        vector<vector<bool>> dp(n,vector<bool>(sum+1,false));
        dp[n-1][0] = true;
        for(int index = n-2; index>=0; index--) {
            for(int target = 0; target <= sum; target++) {
                int take = false;
                if(target >= nums[index]) {
                    take = dp[index+1][target - nums[index]];
                }

                bool nottake = dp[index+1][target];

                dp[index][target] = take || nottake;
            }
        }

        return dp[0][sum];


    }
};