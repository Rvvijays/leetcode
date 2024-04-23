class Solution {
public:
    void generate(int index, vector<int> &curr, int target, vector<int> &nums, vector<vector<int>> &ans ){
        if(index < 0){
            if(target == 0){
                ans.push_back(curr);
            }
            return;
        }

        generate(index-1, curr, target,nums,ans);

        if(target>=nums[index]){
            curr.push_back(nums[index]);
            generate(index,curr,target - nums[index],nums,ans);
            curr.pop_back();
        }


    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int> curr;

        generate(candidates.size()-1, curr,target,candidates,ans);

        return ans;
        
    }
};