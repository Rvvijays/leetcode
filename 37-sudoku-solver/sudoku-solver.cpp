class Solution {
public:

    bool isPossible(int row,int col,  vector<vector<char>>& board,char num){

        for(int i = 0; i<9; i++){

            if(board[row][i] == num){
                return false;
            }
            
            if(board[i][col]== num ){
                return false;
            }

           if (board[3 * (row/3) + i/3][3*(col/3) + i%3] == num) {
               return false;
           }


        }

        return true;
    }

    bool generate(vector<vector<char>>& board){
      
        for(int i=0; i<board.size(); i++){
            for(int j = 0; j<board.size(); j++){

                if(board[i][j] == '.'){
                    for(int k = '1'; k<= '9'; k++){
                        if(isPossible(i,j,board,k)){
                            board[i][j] = k;
                            if(generate(board)){
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;

    }
    void solveSudoku(vector<vector<char>>& board) {

        generate(board);

        
    }
};