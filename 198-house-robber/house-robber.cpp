class Solution {
public:

    int recursion(int index, vector<int> &nums){
        if(index == nums.size()-1){
            return nums[index];
        }

        if(index>=nums.size()) {
            return 0;
        }


        int pick = nums[index] + recursion(index+2,nums);
        int notPick = 0 + recursion(index+1,nums);

        return max(pick,notPick);
    }

    int recursion2(int index, vector<int> &nums){
        if(index == 0){
            return nums[0];
        }

        if(index < 0){
            return 0;
        }

        int take = nums[index] + recursion2(index - 2,nums);
        int notTake = 0 + recursion2(index - 1, nums);

        return max(take,notTake);
    }


  int memorization2(int index, vector<int> &nums,vector<int> &dp){
        if(index == 0){
            return nums[0];
        }

        if(index < 0){
            return 0;
        }

        if(dp[index]!=-1){
            return dp[index];
        }

        int take = nums[index] + recursion2(index - 2,nums);
        int notTake = 0 + recursion2(index - 1, nums);

        return dp[index] = max(take,notTake);
    }

    int tabulation2(int n,vector<int> &nums){
        vector<int> dp(n,0);
        dp[0] = nums[0];

        for(int i=1; i<n; i++){
           
            int notTake = dp[i-1];
            int take = nums[i];
            if(i>1){
                take +=  dp[i-2];
                
            }

            dp[i] = max(take,notTake);

        }

        return dp[n-1];
    }

    int spaceOptimized(int n,vector<int> &nums){
        // vector<int> dp(n,0);
        // dp[0] = nums[0];

        int prev1 = nums[0];
        int prev2 = 0;
        int curr = 0;

        for(int i=1; i<n; i++){
           
            int notTake = prev1;
            int take = nums[i];
            if(i>1){
                take +=  prev2;
            }

            curr = max(take,notTake);
            prev2 = prev1;

            prev1 = curr;

        }

        return prev1;
    }

  
    int memorization(int index, vector<int> &nums, vector<int> &dp){
         if(index == nums.size()-1){
            return nums[index];
        }

        if(index>=nums.size()) {
            return 0;
        }


        if(dp[index]!=-1){
            return dp[index];
        }

        int pick = nums[index] + recursion(index+2,nums);
        int notPick = 0 + recursion(index+1,nums);

        return dp[index] = max(pick,notPick);
    }

    int tabulation(vector<int> & nums){
        int n = nums.size();

        vector<int> dp(n+1,0);
        dp[n-1] = nums[n-1];

        for(int i=n-2; i>=0; i--){
            int notpick = dp[i+1];
            int pick = nums[i];
            // if(i>1){
                pick += dp[i+2];
            // }

            dp[i] = max(pick,notpick);
        }
        return dp[0];
    }
    int rob(vector<int>& nums) {

        // return recursion(0,nums);
        // vector<int> dp(nums.size(),-1);
        // return memorization(0,nums,dp);

        // return recursion2(nums.size()-1,nums);
        // return memorization2(nums.size()-1,nums,dp);
        // return tabulation2(nums.size(),nums);
        return spaceOptimized(nums.size(),nums);
       
    }
};