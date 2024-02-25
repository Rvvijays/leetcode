class Solution {
public:

    bool isPossible(int i,int j, vector<string> &curr){
        
        // left top

        int x = i;
        int y = j;
        while(x >= 0 && y>=0){
            if(curr[x][y] == 'Q'){
                return false;
            }

            x--;
            y--;
        }

        x = i;
        y = j;
        while(x<curr.size() && y>=0){
            if(curr[x][y] =='Q'){
                return false;
            }
            x++;
            y--;
        }
 x = i;
        y = j;
        while(y>=0){
            if(curr[x][y] == 'Q'){
                return false;
            }

            y--;
        }

        return true;
    }

    void generate(int col, vector<string> &curr, vector<vector<string>> &ans, int n){

       

        if(col == n) {
            ans.push_back(curr);
            return;
        }

        for(int i=0; i<n; i++){
            if(isPossible(i,col,curr)){
                curr[i][col] = 'Q';
                generate(col + 1, curr,ans,n);
                curr[i][col] = '.';
            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;

        vector<string> board(n);
        string s(n,'.');
        for(int i=0; i<n; i++){
            board[i] = s;
        }
        

        generate(0,board,ans,n);

        return ans;
        
    }
};