class Solution {
public:

    // string reverse(string s){

    // }
    int longestPalindromeSubseq(string s) {

        string s2 = s;

        reverse(s.begin(),s.end());

        // cout<<"s: "<<s<<endl;
        // cout<<"s2: "<<s2<<endl;

        int n = s.size();

        vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        for(int index1 = 1; index1<=n; index1++){
            for(int index2=1; index2<=n; index2++){
                if(s[index1-1] == s2[index2-1]){
                    dp[index1][index2] =1 + dp[index1-1][index2-1];
                }else{
                    dp[index1][index2] = max(dp[index1-1][index2],dp[index1][index2-1]);
                }
            }
        }

        // int i = n;
        // int j = n;

        // string ans = "";

        // while(i>0 && j>0){
        //     if(s2[i-1] == s[j-1]){
        //         ans += s[i-1];
        //         i--;
        //         j--;

        //     }else{
        //         if(s2[i-1] > s[j-1]) {
        //             j--;

        //         }else{
        //             i--;
        //         }

        //     }
        // }

        return dp[n][n];

    }
};