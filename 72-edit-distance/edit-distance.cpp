class Solution {
public:
    int recursion(int i, int j, string word1, string word2){

        if(j<0){
            return 1;
        }

        if(i<0){
            return 0;
        }

        if(word1[i] == word2[j]) {
            // matched go to check next char.
            return recursion(i-1,j-1,word1,word2);

        }

            // we have three options
            // 1. delete

            int delop = 1 + recursion(i-1,j,word1,word2);
            int repop = 1 + recursion(i-1,j-1,word1,word2);
            int insop = 1 + recursion(i,j-1,word1,word2);

            return min(delop,min(repop,insop));


        
    }

    int memorization(int i, int j, string word1, string word2,vector<vector<int>> &dp){
        if(i==0 ){
            
                return j;
            
        }

        if(j==0){
            return i;
        }

        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(word1[i-1] == word2[j-1]) {
            // matched go to check next char.
            return dp[i][j] = memorization(i-1,j-1,word1,word2,dp);

        }

            // we have three options
            // 1. delete

            int delop = 1 + memorization(i-1,j,word1,word2,dp);
            int repop = 1 + memorization(i-1,j-1,word1,word2,dp);
            int insop = 1 + memorization(i,j-1,word1,word2,dp);

            return dp[i][j] = min(delop,min(repop,insop));


        
    }


    int minDistance(string word1, string word2) {

        

        int n = word1.size();
        int m = word2.size();

        cout<<"size:"<<n<<endl;

        // if(word1 == word2){
        //     return 0;
        // }

        // if(n == 0 || m == 0){
        //     return n>m?n:m;
        // }



        // return recursion(n-1,m-1,word1,word2);
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return memorization(n,m,word1,word2,dp);
        
    }
};