
class Solution {
public:

    void generate(int index, vector<int> &curr, vector<int>& nums, set<vector<int>> &ans){
        if(index == nums.size()) {
            // if(curr.size()>0) {
                ans.insert(curr);
            // }

            return;
        }


        curr.push_back(nums[index]);
        generate(index+1,curr,nums,ans);
        curr.pop_back();
        generate(index+1,curr,nums,ans);
    }


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());
       set<vector<int>> ans;

        vector<int> curr;
       generate(0,curr, nums,ans);

       vector<vector<int>> ss;

        
       for(auto it : ans) {
        ss.push_back(it);
       }

       return ss; 
        
    }
};