class Solution {
public:
    bool recursion(int index, int sumA, int sumB,vector<int>& nums){
        if(index == nums.size()){
            if(sumA == sumB){
                return true;
            }

            return false;
        }


        bool case1 = recursion(index + 1, sumA + nums[index], sumB, nums);
        bool case2 = recursion(index + 1, sumA, sumB + nums[index], nums);

        return case1 || case2;
    }

    bool memorization(int index, int sumA, int sumB,vector<int>& nums ,vector<vector<int>> &dp1, vector<vector<int>> &dp2){
        if(index == nums.size()){
            if(sumA == sumB){
                return true;
            }

            return false;
        }

        if(dp1[index][sumA]!=-1 && dp2[index][sumB]!=-1){
            return dp1[index][sumA] || dp2[index][sumB];
        }


        bool case1 = memorization(index + 1, sumA + nums[index], sumB, nums,dp1,dp2);
        bool case2 = memorization(index + 1, sumA, sumB + nums[index], nums,dp1,dp2);
        dp1[index][sumA] = case1;
        dp2[index][sumB] = case2;

        return case1 || case2;
    }

    bool tabulation(vector<int>& nums){
        int n = nums.size();
        vector<vector<bool>> dp1(n+1,vector<bool>(20000,false));
        vector<vector<bool>> dp2(n+1,vector<bool>(20000,false));

        for(int index = n; index>=0; index--){
            for(int sumA=0; sumA<20001; sumA++){
                for(int sumB=0; sumB<20001; sumB++){

                    if(index == n){
                        if(sumA == sumB){
                            dp1[index][sumA] = true;
                            dp2[index][sumB] = true;
                        }
                        continue;
                    }

                    bool case1 = dp1[index + 1][sumA + nums[index]];
                    bool case2 = dp2[index + 1][sumB + nums[index]];

                    dp1[index][sumA] = case1;
                    dp2[index][sumB] = case2;

                    // return case1 || case2;
                }
            }
        }

        return dp1[0][0] && dp2[0][0];


    }

    bool recursion2(int index, int target, vector<int> &nums, vector<vector<int>> &dp){
        if(index == nums.size()) {
            if(target == 0){
                return true;
            }

            return false;
        }

        if(dp[index][target]!=-1){
            return dp[index][target];
        }

        int take = false;
        if(target >= nums[index]){
            take = recursion2(index + 1, target - nums[index], nums,dp);
        }
        int notTake = recursion2(index + 1, target, nums,dp);

        return dp[index][target] = take || notTake;

    }

    bool canPartition(vector<int>& nums) {
        // return recursion(0,0,0,nums);

        int n = nums.size();
        // vector<vector<int>> dp1(n,vector<int>(20000,-1));
        // vector<vector<int>> dp2(n,vector<int>(20000,-1));
        // return memorization(0,0,0,nums,dp1,dp2);

        // return tabulation(nums);

        int totSum = 0;
        for(int i=0; i<n; i++){
            totSum += nums[i];
        }

        if(totSum%2==1){
            return false;
        }

        int target = totSum/2;

        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return recursion2(0,target,nums,dp);
        
    }
};