class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        stack<int> st;

        // vector<int> nge(nums2.size(),-1);
        unordered_map<int,int> mp;

        for(int i=nums2.size()-1; i>=0; i--){
            int num = nums2[i];

           while(!st.empty() && st.top() < num){
            st.pop();
           }

           if(!st.empty()){
            // nge[i] = st.top();
            mp[num] = st.top();
           }else{
            mp[num] = -1;
           }

            st.push(num);



        }

        for(int i=0; i<nums1.size(); i++){
            nums1[i] = mp[nums1[i]];
        }

        return nums1;
    }
};