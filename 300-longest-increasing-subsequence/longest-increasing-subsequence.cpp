class Solution {
public:
    // void recursion(int index, vector<int> curr, vector<int> &nums) {
    //     if(index == nums.size()) {
    //         for(int i=0; i<curr.size(); i++) {
    //             cout<<curr[i]<<" ";
    //         }
    //         cout<<endl;
    //         return;
    //     }

    //     curr.push_back(nums[index]);
    //     recursion(index+1,curr,nums);

    //     curr.pop_back();
    //     recursion(index+1,curr,nums);
        
    // }

    int recursion(int index, int prev, int n, vector<int> &nums,vector<vector<int>> &dp) {
        if(index == n) {
            return 0;
        }
        
        if(dp[index][prev+1] !=-1) {
            return dp[index][prev+1];
        }

        if(prev == -1 || nums[prev] < nums[index]){
            return dp[index][prev+1] = max(1 + recursion(index+1,index,n,nums,dp), recursion(index+1,prev,n,nums,dp));
        }
        return dp[index][prev+1] = recursion(index+1,prev,n,nums,dp);
    }


    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();

    //     vector<vector<int>> dp(n+1,vector<int>(n+1,1));

    //    for(int index = n; index > 0; index--) {
    //     for(int prev = 0; prev <= index; prev++) {
    //         if(prev == 0 || nums[prev-1] < nums[index-1]){
    //             dp[index][prev] = max(1 + dp[index+1][index], dp[index+1][prev]);
    //         }else{
    //             dp[index][prev] = dp[index+1][prev];
    //         }
            
    //     }
    //    }

   
    //    return dp[1][0];


        // vector<int> curr;
          vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return recursion(0,-1,n,nums,dp);

    }
};