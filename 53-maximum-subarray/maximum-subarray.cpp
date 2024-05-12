class Solution {
public:
    
   
    int maxSubArray(vector<int>& nums) {
        // greedy approach.

        int curr = 0;
        int maxi = nums[0];

        for(int i = 0; i < nums.size(); i++){
            curr += nums[i];

            if (curr > maxi){
                maxi = curr;
            }

            if (curr < 0){
                curr = 0;
            }
        }

        return maxi;

    }
};