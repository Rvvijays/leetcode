class Solution {
public:

    void generate(int index,vector<int> curr, int currSum,int sum, vector<int> &arr, vector<vector<int>> &ans){

        if(index == arr.size()){
            if(currSum == sum){
                ans.push_back(curr);
               
            }
             return;
        }

        // pick

        if(currSum + arr[index] <= sum){
            curr.push_back(arr[index]);
            generate(index,curr,currSum+arr[index],sum,arr,ans);
            // generate(index+1,curr,currSum+arr[index],sum,arr,ans);
             curr.pop_back();

        }
       

        //not pick
       
        generate(index+1,curr,currSum,sum,arr,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int> curr;

        generate(0,curr,0,target,candidates,ans);

        return ans;
        
    }
};