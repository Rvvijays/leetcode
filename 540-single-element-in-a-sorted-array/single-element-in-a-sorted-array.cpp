class Solution {
public:

    int brute(vector<int> &nums) {

        int n = nums.size();

        if(n == 1){
            return nums[0];
        }

        if(nums[0]!=nums[1]){
            return nums[0];
        }

        if(nums[n-1]!= nums[n-2]){
            return nums[n-1];
        }


        for(int i=1; i<nums.size()-1; i++){

            int a = nums[i];

            if(nums[i-1]!=a && nums[i+1]!=a){
                return a;
            }

        }

        return -1;
    }

    int optimal(vector<int> &nums){

        int n = nums.size();

        if(n == 1){
            return nums[0];
        }

        if(nums[0] != nums[1]){
            return nums[0];

        }


        if(nums[n-1]!= nums[n-2]){
            return nums[n-1];
        }

        int low = 1;
        int high = n-2;

        while(low <= high) {
            int mid = (low + high)/2;

            if(nums[mid-1]!=nums[mid] && nums[mid]!= nums[mid+1]){
                return nums[mid];
            }


           if((mid%2==0 && nums[mid] == nums[mid-1]) || (mid%2==1 && nums[mid]== nums[mid+1])){
               high = mid -1;
           }else{
               low = mid + 1;
           }
        }

        return -1;

    }
    int singleNonDuplicate(vector<int>& nums) {

        return optimal(nums);
        
    }
};