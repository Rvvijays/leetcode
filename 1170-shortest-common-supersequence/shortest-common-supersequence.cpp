class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {

        int n = str1.size();
        int m = str2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1,0));

        for(int index1=1; index1<=n; index1++){
            for(int index2=1; index2<=m; index2++){
                if(str1[index1-1] == str2[index2-1]){
                    dp[index1][index2] = 1 + dp[index1-1][index2-1];
                }else{
                    dp[index1][index2] = max(dp[index1-1][index2],dp[index1][index2-1]);
                }
            }
        }

        string cms = "";
        int len = dp[n][m];

        int index1 = n;
        int index2 = m;

        while(index1>0 && index2>0) {

            if(str1[index1-1] == str2[index2-1]){
                cms += str1[index1-1];
                index1--;
                index2--;

            }else{

                if(dp[index1-1][index2]>dp[index1][index2-1]){
                    cms += str1[index1-1];
                    index1--;
                }else{
                    cms += str2[index2-1];
                    index2--;
                }

            }

        }
        while(index1>0){
            cms += str1[index1-1];
            index1--;
        }

        while(index2>0){
            cms += str2[index2-1];
            index2--;
        }

        cout<<"string:"<<cms<<endl;

        reverse(cms.begin(),cms.end());



      
      return cms;



        
    }
};