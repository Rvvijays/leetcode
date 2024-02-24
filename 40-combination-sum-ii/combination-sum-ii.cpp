class Solution {
public:

    void generate(int index, vector<int> &curr, int target,vector<int> &arr, vector<vector<int>> &ans){

        // if(index == arr.size()){
            if(target == 0){
                ans.push_back(curr);
                return;
            }
        //     return;
        // }

        //while(index < arr.size() && index)


        for(int i = index; i<arr.size(); i++){

            if(i > index && arr[i] == arr[i-1]){
                continue;
            }

            if(arr[i] > target){
                break;
            }

            // if(arr[i] <= target) {
                curr.push_back(arr[i]);
                generate(i+1,curr,target-arr[i],arr,ans);
                curr.pop_back();
            // }

            // generate(i+1,curr,target,arr,ans);


        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int> curr;

        sort(candidates.begin(), candidates.end());

        generate(0,curr,target,candidates,ans);

        return ans;

        
    }
};