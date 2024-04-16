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

    bool canPartition(vector<int>& nums) {
        // return recursion(0,0,0,nums);

        int n = nums.size();
        vector<vector<int>> dp1(n,vector<int>(20000,-1));
        vector<vector<int>> dp2(n,vector<int>(20000,-1));
        return memorization(0,0,0,nums,dp1,dp2);
        
    }
};