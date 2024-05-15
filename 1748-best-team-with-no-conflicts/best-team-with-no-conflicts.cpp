class Solution {
public:

    int recursion(int index, int prev, vector<pair<int,int>>& list, vector<vector<int>> &dp) {
        if (index == list.size()) {
            return 0;
        }

        if(dp[index][prev+1] != -1) {
            return dp[index][prev+1];
        } 

        int pick = 0;


        if(prev ==-1 || list[prev].second <= list[index].second ) {
            // chosen[ages[index]] = true;;
            pick =  list[index].second + recursion(index+1,index,list,dp);
            // chosen.erase(ages[index]);
        }

        int notPick = recursion(index+1,prev,list,dp);

        return dp[index][prev+1] =  max(pick,notPick);




    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {

        vector<pair<int,int>> list;


        int n = ages.size();

        for(int i=0; i<n; i++) {
            list.push_back({ages[i],scores[i]});
        }

        sort(list.begin(),list.end());

        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        return recursion(0,-1,list,dp);
    }   
};