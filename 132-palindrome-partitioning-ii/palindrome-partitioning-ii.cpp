class Solution {
public:

    bool check(int i, int j, string &s) {
        while(i <= j) {
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }

        return true;
    }

    int recursion(int index, int n, string s, vector<int> &dp) {
        if(index == n){
            return 0;
        }

        if(dp[index]!=-1){
            return dp[index];
        }

        int minCost = INT_MAX;
        for(int j=index; j<n; j++) {
            if(check(index,j,s)) {
                int cost = 1 + recursion(j+1,n,s,dp);

                minCost = min(cost,minCost);
            }
        }

        return dp[index] = minCost;
    }
    int minCut(string s) {

        int n = s.size();

        // vector<int> dp(n+1,-1);
        // return recursion(0,n,s,dp) - 1;

        vector<int> dp(n+1,0);
        for(int index = n-1; index>=0; index--) {
            int minCost = INT_MAX;
            for(int j=index; j<n; j++) {
                if(check(index,j,s)) {
                    int cost = 1 + dp[j+1];

                    minCost = min(cost,minCost);
                }
            }

            dp[index] = minCost;
        }

        return dp[0] - 1;

        
    }
};