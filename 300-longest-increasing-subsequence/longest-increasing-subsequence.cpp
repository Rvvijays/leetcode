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
        
        if(dp[index][prev] !=-1) {
            return dp[index][prev];
        }

        if(prev == 0 || nums[prev-1] < nums[index-1]){
            return dp[index][prev] = max(1 + recursion(index+1,index,n,nums,dp), recursion(index+1,prev,n,nums,dp));
        }
        return dp[index][prev] = recursion(index+1,prev,n,nums,dp);
    }


    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();

        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        // vector<int> curr;
        return recursion(1,0,n+1,nums,dp);

    }
};