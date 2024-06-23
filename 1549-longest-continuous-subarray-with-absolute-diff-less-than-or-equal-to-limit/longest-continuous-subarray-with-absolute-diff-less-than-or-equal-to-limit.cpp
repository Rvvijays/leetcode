class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {

        int n = nums.size();

        int i = 0;
        int j = 0;
        int mini = nums[i];
        int maxi = nums[i];
        int maxLen = 0;
        while (j < n) {

            int diff = abs(maxi - mini);


            if (i < n && diff > limit) {
                i++;
                if(i < n) {
                    mini = nums[i];
                    maxi = nums[i];
                    for(int num = i; num <= j; num++) {
                        mini = min(nums[num],mini);
                        maxi = max(nums[num], maxi);
                    }
                    diff = abs(maxi - mini);
                }
                
            }

           

            maxLen = max(maxLen,j - i + 1);
            j++;
            if(j == n) {
                break;
            }
            mini = min(nums[j],mini);
            maxi = max(nums[j], maxi);
            
        }



        return maxLen;


    }
};