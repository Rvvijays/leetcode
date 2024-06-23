class Solution {
public:

    int brute(vector<int>& nums, int limit) {
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
    int longestSubarray(vector<int>& nums, int limit) {

        int n = nums.size();


        multiset<int> st;
        int i =0;
        int j = 0;

        int maxLen = 0;

        while( j < n) {
            st.insert(nums[j]);

            while(*st.rbegin() - *st.begin() > limit) {
                st.erase(st.find(nums[i]));
                i++;
            }

            maxLen = max(maxLen, j - i + 1);

            j++;


        }

        return maxLen;

       


    }
};