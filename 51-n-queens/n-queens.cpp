class Solution {
public:

    bool isValid(int x,int y, int n, vector<string> &curr){

        // for(int i=0; i<n; i++){
        // cout<<curr[i]<<endl; 
        // }

        // cout<<"checking x:"<<x<<" y:"<<y<<endl;

        int i = x;
        int j = y;

        for(int i=0; i<n; i++){
            if(curr[i][y] == 'Q'){
                return false;
            }

            if(curr[x][i]=='Q'){
                return false;
            }
        }

         i = x;
         j = y;

        while(i>=0 && j>=0){
            if(curr[i][j]=='Q'){
                return false;
            }

            i--;
            j--;
        }



         i = x;
         j = y;

        while(i>=0 && j<n){
            if(curr[i][j]=='Q'){
                return false;
            }

            i--;
            j++;
        }


         i = x;
         j = y;

        while(j>=0 && i<n){
            if(curr[i][j]=='Q'){
                return false;
            }

            j--;
            i++;
        }
            i = x;
         j = y;
        while(j<n && i <0){
            if(curr[i][j]=='Q'){
                return false;
            }

            i++;
            j++;
        }

        
        return true;

        // verticle

        // horizontal
        // diagonal


    }

    void generate(int row, int n, vector<string> &curr, vector<vector<string>> &ans){


        if(row == n){
            // cout<<"added to ans"<<endl;
            ans.push_back(curr);
            return;
        }
        
        // int dx[4] = {0,0,1,-1};
        // int dy[4] = {1,-1,0,0};

        for(int i=0; i<n; i++){

            if(isValid(row,i,n,curr)){
                curr[row][i] = 'Q';
               generate(row+1,n,curr,ans);
                curr[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        
        string s = "";
        for(int i=0; i<n; i++){
            s += ".";
        }

        
        vector<string> curr(n,s);

        generate(0,n,curr,ans);

        return ans;
    }
};