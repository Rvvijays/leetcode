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

        int len = recursion(index+1,prev,n,nums,dp);
        
        if(prev == -1 || nums[prev] < nums[index]){
             len = max(1 + recursion(index+1,index,n,nums,dp),len);
        }
        return dp[index][prev+1] = len;
    }


    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();

  
         vector<vector<int>> dp(n+1,vector<int>(n+1,0));

         for(int index = n-1; index >= 0; index--) {
            for(int prev = index-1; prev >=-1; prev--) {

               int len = dp[index+1][prev+1];
        
                if(prev == -1 || nums[prev] < nums[index]){
                    len = max(1 + dp[index+1][index+1],len);
                }
                 dp[index][prev+1] = len;
                
            }
         }

         return dp[0][0];



        // vector<int> curr;
        //   vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        // return recursion(0,-1,n,nums,dp);

    }
};