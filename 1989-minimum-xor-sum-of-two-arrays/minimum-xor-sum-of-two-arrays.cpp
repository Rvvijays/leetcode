class Solution {
public:
    int recursion(int index, vector<int> &nums1, vector<int>& nums2, vector<int>& cap,
    map<vector<int>,int> &mp
    ) {
        if(index >= nums1.size()) {
            return 0;
        }

        if(mp.find(cap)!=mp.end()){
            return mp[cap];
        }

        int mini = INT_MAX;

        for(int i = 0; i<nums2.size(); i++) {
            if(cap[i] == 0) {
                cap[i]++;
                mini = min(mini,(nums1[index] ^ nums2[i]) + recursion(index+1,nums1,nums2,cap,mp));
                cap[i]--;
            }
        }

        return mp[cap] = mini;
    }
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> cap(n,0);
        map<vector<int>,int> mp;
        return recursion(0,nums1, nums2, cap,mp);
        
    }
};