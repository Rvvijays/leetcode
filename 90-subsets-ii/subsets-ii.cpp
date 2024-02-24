class Solution {
public:

    void generate(int index, vector<int> &curr, vector<int> &arr, set<vector<int>> &ans){

        if(index == arr.size()){
            ans.insert(curr);
            return;
        }

        curr.push_back(arr[index]);
        generate(index+1,curr,arr,ans);
        curr.pop_back();
        generate(index+1,curr,arr,ans);
    }

    void optimal(int index, vector<int> &curr, vector<int> &arr, vector<vector<int>> &ans){

        ans.push_back(curr);


        for(int i=index; i<arr.size(); i++){
            if(i>index && arr[i]==arr[i-1]){
                continue;
            }

            curr.push_back(arr[i]);
            optimal(i+1,curr,arr,ans);
            curr.pop_back();
        }
        


    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        // set<vector<int>> ans;
        // vector<int> curr;

        sort(nums.begin(),nums.end());

        // generate(0,curr,nums,ans);

        // vector<vector<int>> anss;
        // for (auto i : ans) {
        //     anss.push_back(i);
        // }

        // return anss;


        vector<vector<int>> ans;
        vector<int> curr;

        optimal(0,curr,nums,ans);
        return ans;


        
    }
};