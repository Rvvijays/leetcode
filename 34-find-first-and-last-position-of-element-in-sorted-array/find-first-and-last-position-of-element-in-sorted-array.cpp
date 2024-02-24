class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // last occurence means lower_bound but if occurence is necessary so if we do not find the target we return -1.
        // and first occurence will be go to left of lower_bound till we get element not equal to target;
        // but we can do other thing also we can do binary search. if we find the element we go right to last occurence and 
        // left for first occurence.
        int low = 0;
        int high = nums.size() - 1;

        vector<int> ans = {-1,-1};

        int index = -1;

        while(low <= high){
            int mid = (low + high)/2;

            if(nums[mid] == target){
                index = mid;
                break;
            }

            if(nums[mid] > target){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

       // cout<<"dounf:"<<low;

        low = index;
        high = index;

       if(low != -1) {
           ans[0] = low;
            while(low >= 0 && nums[low] == target){
                ans[0] = low;
                //cout<<"adding:"<<low;
                low--;
            }
        
       }



       if(high != -1) {
           ans[1] = high;
            while(high < nums.size() && nums[high] == target){
                ans[1] = high;
                high++;
            }
        
       }

      
      return ans;
       


      
    }
};