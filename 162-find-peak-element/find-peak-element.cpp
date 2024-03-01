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

    int optimal(vector<int> &nums) {
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

        int low = 1;
        int high = n-2;

        while(low<=high){
            int mid = (low+high)/2;

            if(nums[mid]> nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid;
            }

            if(nums[mid-1] < nums[mid]  && nums[mid] < nums[mid+1]){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }

        return -1;


    }

    int findPeakElement(vector<int>& nums) {

        // return brute(nums);

        return optimal(nums);
        
    }
};