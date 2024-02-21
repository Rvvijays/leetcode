class Solution {
public:
    void generate(int index, vector<int> &curr, vector<vector<int>> &ans ,vector<int> &nums){

        if(index >= nums.size()){
            ans.push_back(curr);
            return;
        }

        //take
        curr.push_back(nums[index]);
        generate(index+1,curr,ans,nums);
        curr.pop_back();
        generate(index+1,curr,ans,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;

        generate(0,curr,ans,nums);

        return ans;
        
    }
};