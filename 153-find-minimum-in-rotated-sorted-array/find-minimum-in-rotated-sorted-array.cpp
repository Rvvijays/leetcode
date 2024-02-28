class Solution {
public:
    int findMin(vector<int>& nums) {

        int low = 0;
        int high = nums.size() - 1;

        int ans = nums[low];

        while(low <= high){
            int mid = (low + high)/2;

            // cout<<"mid: "<<nums[mid];
             if(ans > nums[mid]){
                    ans = nums[mid];
                }

            if(nums[low]<=nums[mid]){
                if(ans > nums[low]){
                    ans = nums[low];
                }
                low = mid + 1;

            } else {
                high = mid - 1;
            }
        }

        return ans;

        
    }
};