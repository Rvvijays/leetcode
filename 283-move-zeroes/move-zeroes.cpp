class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int n = nums.size();

        int left = 0;
        int right =0;

        while(right < n && left < n){

            while(left < n && nums[left]!=0){
                left++;
            }

            right = left;

            while(right<n && nums[right]==0){
                right++;
            }

            // cout<<"left: "<<left<<" right:"<<right<<endl;

            if(left < n && right < n && left < right){
                // cout<<"swap"<<endl;
                swap(nums[left],nums[right]);

            }

            left++;
        }



    }
    
};