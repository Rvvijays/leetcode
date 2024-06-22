class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        unordered_map<int,int> mp;

        int oddCount = 0;
        mp[oddCount] = 1;
        int ans = 0;
        for (int i=0; i<nums.size(); i++) {

            oddCount += nums[i] % 2;
            int need = oddCount - k;

            if (mp.find(need) != mp.end()) {
                ans += mp[need];
            }
            
            mp[oddCount]++;
        }

        return ans;
        
    }
};