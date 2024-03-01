class Solution {
public:

    int brute(vector<int> &nums) {
        int n = nums.size();
        if(n == 1){
            return 0;
        }

        if(nums[0] > nums[1]){
            return 0;
        }

        if(nums[n-1]> nums[n-2]){
            return n-1;
        }

        for(int i=1; i<n-1; i++){
            int a = nums[i];

            if(a > nums[i-1] && a > nums[i+1]){
                return i;
            }
        }

        return -1;
    }

    int findPeakElement(vector<int>& nums) {

        return brute(nums);
        
    }
};