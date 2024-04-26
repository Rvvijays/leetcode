class Solution {
public:

    int recursion1(int index, int prev_index, vector<int> &nums){

        if(index == nums.size()){
            return 0;
        }

        if(prev_index == -1 || (nums[prev_index]%nums[index] == 0 || nums[index] % nums[prev_index]==0)){
            return max(1 + recursion1(index+1,index,nums), recursion1(index+1,prev_index,nums));
        }

        return recursion1(index+1,prev_index,nums);

    }

   
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        int n = nums.size();
        vector<int> curr(n,1);
        vector<int> hash(n);
        sort(nums.begin(), nums.end());
        // recursion(0,-1,nums,curr,dp);

        int lastIndex = -1;
        int maxi = -1;

        for(int i=0; i<n; i++){
            hash[i] = i;
            for(int j=0; j<i; j++){
                if(nums[i]%nums[j]==0 && 1 + curr[j] > curr[i]) {
                    curr[i] = 1+ curr[j];
                    hash[i] = j;
                }
            }

            if(maxi < curr[i]){
                maxi = curr[i];
                lastIndex = i;
            }
        }


        vector<int> temp;
        temp.push_back(nums[lastIndex]);
        while(hash[lastIndex]!=lastIndex){
            temp.push_back(nums[hash[lastIndex]]);
            lastIndex = hash[lastIndex];
        }

        reverse(temp.begin(),temp.end());

        return temp;




        
    }
};