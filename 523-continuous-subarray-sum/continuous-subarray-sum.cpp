class Solution {
public:

    bool brute(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j <= i; j++) {
                sum += nums[j];
                if (sum % k == 0) {
                    return true;
                }
            }
        }
        return false;
    }

    bool checkSubarraySum(vector<int>& nums, int k) {
        // return brute(nums,k);

        unordered_map<int,int> mp;
        mp[0] = -1;
        int sum = 0;
        for (int i=0; i <nums.size(); i++) {
            sum += nums[i];

            int rem = sum % k;

            if(mp.find(rem) != mp.end()) {
                int len = i - mp[rem];
                if(len>=2) {
                    return true;
                }
            }else{
                mp[rem] = i;

            }

        }

        return false;
    }


    
};