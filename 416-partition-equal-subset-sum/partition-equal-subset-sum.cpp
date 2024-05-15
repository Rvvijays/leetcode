class Solution {
public:

    bool recursion(int index, int target, vector<int>& nums,vector<vector<int>> &dp) {

        if(index == nums.size()-1) {
            if(target == 0) {
                return true;
            }

            return false;
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

        int target = totalSum/2;

        vector<vector<int>> dp(n,vector<int>(target+1,-1));

        return recursion(0,target,nums,dp);
    }
};