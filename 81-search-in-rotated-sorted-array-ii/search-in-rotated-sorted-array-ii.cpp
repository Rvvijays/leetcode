class Solution {
public:
    bool search(vector<int>& nums, int target) {
          int low = 0;
        int high = nums.size() - 1;

        while(low <= high) {
            int mid = (low + high)/2;

            if(nums[mid] == target){
                return true;
            }

            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                low++;
                high--;
                continue;
            }

           // check if left part is sorted or not.
           if(nums[low] <= nums[mid]) {
            if(nums[low] <= target && target <= nums[mid]){
                // and target is in left part
                high = mid - 1;
            }else{
                low = mid + 1;
            }
           }else{
             if(nums[mid] <= target && target <= nums[high]){
                // and target is in left part
                low = mid + 1;
            }else{
                high = mid - 1;
            }
           }
        }

        return false;
    }
};