class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        int n1 = nums1.size();
        int n2 = nums2.size();

        if (n2 < n1) {
            return intersect(nums2,nums1);
        }


        unordered_map<int,int> counts;
        for (int i=0; i<n2; i++) {
            counts[nums2[i]]++;
        }

        vector<int> ans;

        for (int i=0; i<n1; i++) {
            int num = nums1[i];

            if (counts[num] > 0) {
                ans.push_back(num);
                counts[num]--;
            }
        }

        return ans;
        
    }
};