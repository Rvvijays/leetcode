class Solution {
public:

    void generate(int num, vector<int> &curr,int digits, int sum, vector<vector<int>> &ans){

        if(digits == 0){
            if(sum == 0){
                ans.push_back(curr);
            }

            return;
        }


        for(int i = num+1; i<10; i++){

            if(sum < i){
                continue;
            }

            curr.push_back(i);
            generate(i,curr,digits-1,sum-i,ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;

        // int minSum = 0;
        // for(int i=1; i<=k; i++){
        //     minSum += i;
        // }

        // if (n < minSum) {
        //     return ans;
        // }

        vector<int> curr;

        generate(0,curr,k,n,ans);

        return ans;
        
    }
};