class Solution {
public:

    int recursion(int index, int target, vector<int> &nums){
        if(index ==0){
            if(nums[0]==0 && target == 0){
                return 2;
            }
            if(target + nums[index] == 0 || target - nums[index] == 0){
                return 1;
            }

            return 0;
        }

        int case2 = recursion(index-1,target-nums[index],nums);


        int num = nums[index] * -1;

        int case1 = recursion(index-1,target - num,nums);

       


        return case1 + case2;


    }


    int recursion2(int index, int target, vector<int> &nums){

        if(index==0){

            if(target ==0 && nums[index]==0){
                return 2;
            }
            if(target==0 || target == nums[index]){
                return 1;
            }

            return 0;
        }

        int notTake = recursion2(index-1,target,nums);

        int take = 0;

        if(target >= nums[index]){
            take = recursion2(index-1,target - nums[index],nums);
        }

        return take + notTake;

    }


  int memorization(int index, int target, vector<int> &nums, vector<vector<int>> &dp){

        if(index==0){

            if(target ==0 && nums[index]==0){
                return 2;
            }

            if(target == nums[index] || target==0){
                return 1;
            }

            return 0;
        }

        if(dp[index][target]!=-1){
            return dp[index][target];
        }

        int notTake = memorization(index-1,target,nums,dp);

        int take = 0;

        if(target >= nums[index]){
            take = memorization(index-1,target - nums[index],nums,dp);
        }

        return dp[index][target] = take + notTake;

    }


    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        // return recursion(n-1,target,nums);

        // already done the problem..

        // s1 - s2 = target;
        // s1 + s2 = totalSum;

        // s1 = (target + totalSum)/ 2;

        // need to find ways of s1;


        int totalSum = 0;
        for(int i=0; i<n; i++) totalSum += nums[i];


        // if()
        int newT = (totalSum - target)/2;


        if(totalSum - target < 0 || (totalSum - target)%2==1){
            return 0;
        }

        cout<<"sum:"<<(totalSum - target)/2<<endl;

        // return recursion2(n-1, newT, nums);

        // if(target > totalSum){
        //     return 0;
        // }

      

        
        vector<vector<int>> dp(n,vector<int>(newT+1,-1));
        return memorization(n-1, newT, nums,dp);
    }
};