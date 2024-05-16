class Solution {
public:

    int recursion(int i, int j, vector<int>& nums,vector<vector<int>> &dp) {
        if(i > j) {
            return 0;
        }

        if(dp[i][j]!=-1) {
            return dp[i][j];
        }

        int maxi = -1e9;
        for(int k=i; k<=j; k++) {
            int cost = nums[i-1] * nums[k] * nums[j+1] + recursion(i,k-1, nums,dp) + recursion(k+1,j,nums,dp);
            maxi = max(cost,maxi);
        }

        return dp[i][j] = maxi;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        nums.insert(nums.begin(),1);
        nums.push_back(1);

        vector<vector<int>> dp(n+2,vector<int>(n+2,-1));

        return recursion(1,n,nums,dp);
        
    }
};