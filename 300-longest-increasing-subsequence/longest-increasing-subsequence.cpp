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

  
        //  vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        //  vector<int> temp(n+1,0);

        //  for(int index = n-1; index >= 0; index--) {
        //     vector<int> curr(n+1,0);
        //     for(int prev = index-1; prev >=-1; prev--) {

        //        int len = temp[prev+1];
        
        //         if(prev == -1 || nums[prev] < nums[index]){
        //             len = max(1 + temp[index+1],len);
        //         }
        //         curr[prev+1] = len;
                
        //     }
        //     temp = curr;
        //  }

        //  return temp[0];



        // another wierd method.

        vector<int> count(n,1);

        int maxi = 1;

        for(int i=1; i< n; i++) {

            for(int j = 0; j< i; j++) {
                if(nums[i] > nums[j] && count[i] < count[j] + 1) {
                    count[i] = count[j] + 1;
                }
            }

            maxi = max(count[i],maxi);
        }

        return maxi;








        // vector<int> curr;
        //   vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        // return recursion(0,-1,n,nums,dp);

    }
};