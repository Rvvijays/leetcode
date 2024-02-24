class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

    
       int low = 0;
       int high = nums.size() - 1;

    //    if(target < nums[0] || high == 0){
    //        return 0;
    //    }

       while(low<=high) {
           int mid = (low + high)/2;

           if(nums[mid] >= target){
               high = mid - 1;
           }else{
               low = mid + 1;
           }
       }

    //    if(nums[low] == target) {
    //        return low;
    //    }

       return low;
        
    }
};