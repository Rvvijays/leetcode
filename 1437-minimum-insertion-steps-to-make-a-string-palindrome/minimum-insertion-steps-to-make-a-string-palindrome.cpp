class Solution {
public:
    int minInsertions(string s1) {

        // int low =0;

        // int high = s.size()  - 1;

        // int count = 0;


        // while(low<=high){
        //     if(s[low] == s[high]){
        //         low++;
        //         high--;
        //     }else{
        //         if(low<high-1 && s[low+1] == s[high]){
        //             count += 1;
        //             low++;
        //         }else if(high > low+1 && s[low] == s[high-1]){
        //             count += 1;
        //             high--;
        //         }else{
        //             count += 2;
        //             low++;
        //             high--;
        //         }
        //     }
        // }

        // return count;
        

        string s2 = s1;
        reverse(s2.begin(), s2.end());
        int n = s1.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));

        for(int index1 = 1; index1<=n; index1++){
            for(int index2 = 1; index2<=n; index2++){

                if(s1[index1-1] == s2[index2-1]){
                    dp[index1][index2] =1+ dp[index1-1][index2-1];

                }else{
                    dp[index1][index2] = max(dp[index1-1][index2], dp[index1][index2-1]);
                }
            }
        }

        return n - dp[n][n];
    }
};