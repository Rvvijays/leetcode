class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        if(nums[0] > target) {
            return 0;
        }

        int ans = high + 1;

        while(low <= high) {
            int mid = (low+high)/2;

            //cout<<"midElem:"<<nums[mid];

            if(nums[mid] >= target) {
                ans = mid;
                high = mid - 1;
               
            }else{
                low = mid + 1;
            }


        }

        return ans;
        
    }
};