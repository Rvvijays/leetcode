class Solution {
public:

    int recursion(int index, int numSlots, vector<int>& nums, vector<int>& cap,
    map<vector<int>,int> &mp) {

        if(index >= nums.size()){
            return 0;
        }

        if(mp.find(cap) !=mp.end()) {
            return mp[cap];
        }


        int maxi = INT_MIN;
        for(int i=1; i<=numSlots; i++) {
            if(cap[i] < 2) {
                cap[i]++;
                maxi = max(maxi, (nums[index] & i) + recursion(index+1,numSlots,nums,cap,mp));
                cap[i]--;

            }
        }

        return mp[cap] = maxi;
        

    }
    int maximumANDSum(vector<int>& nums, int numSlots) {

        vector<int> cap(numSlots+1,0);

        map<vector<int>,int> mp;
        

        return recursion(0,numSlots,nums,cap,mp);
        
    }
};