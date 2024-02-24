class Solution {
public:

    void generate(int index, vector<int> &curr, vector<int> &arr, set<vector<int>> &ans){

        if(index == arr.size()){
            ans.insert(curr);
            return;
        }



        // for(int i=index; i<arr.size(); i++){
        //     if(i>index && arr[i] == arr[i-1]){
        //         continue;
        //     }

            curr.push_back(arr[index]);
            generate(index+1,curr,arr,ans);
            curr.pop_back();
            generate(index+1,curr,arr,ans);
        // }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        set<vector<int>> ans;
        vector<int> curr;

        sort(nums.begin(),nums.end());

        generate(0,curr,nums,ans);

        vector<vector<int>> anss;
        for (auto i : ans) {
            anss.push_back(i);
        }

        return anss;
        
    }
};