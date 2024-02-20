class Solution {
public:

    vector<int> brute(vector<int>& nums, int target){
        vector<int> ans = {-1,-1};

        for(int i=0; i<nums.size(); i++){
            if(nums[i] == target) {

                if(ans[0] == -1){
                    ans[0] = i;
                }

                ans[1] = i; 
            }
        }

        return ans;
    }

    int lowerBound(vector<int>& nums, int target){
        int low = 0;
        int high = nums.size() - 1;

        int ans = -1;

        while(low <= high) {
            int mid = (low+high)/2;

            

            if(nums[mid] >= target) {
                high = mid - 1;
                ans = mid;
            }else{
                low = mid + 1;
            }
        }

        if(ans!=-1 && nums[ans] != target){
            return -1;
        }

        return ans;

    }
    int upperBound(vector<int>& nums, int target){
        int low = 0;
        int high = nums.size() - 1;

        int ans = -1;

        while(low<=high){
            int mid = (low+high)/2;

            if(nums[mid] <= target){
                low = mid + 1;
                ans = mid;
            }else{
                high = mid - 1;
            }
        }

        if(ans!=-1 && nums[ans]!=target){
            ans = -1;
        }

      

        return ans;
        
    }
    vector<int> searchRange(vector<int>& nums, int target) {

        vector<int> ans = {-1,-1};

         ans[0] = lowerBound(nums,target);
         ans[1] = upperBound(nums,target);

        // cout<<"target: "<<first;

        return ans;





      
    }
};