class Solution {
public:

    bool check(int i,int j, int index,vector<vector<int>> &vis, vector<vector<char>>& board, string word,int n,int m){
        if(index == word.length()){
            return true;
        }

        if( i<0 || j<0 || i==n || j==m || board[i][j] != word[index] || vis[i][j] == 1){
            return false;
        }


        // vector<int> dx = {0,1,-1,0};
        // vector<int> dy = {1,0,0,-1};


        // for(int k=0; k<4; k++){
        //     int x = i + dx[k];
        //     int y = j + dy[k];
           

        //     if(x>=0 && x < n && y >=0 && y<m){                  
        //         if(vis[x][y] == -1){
        //             vis[x][y] = 1;

        //             if(check(x,y,index+1,vis,board,word,n,m)){
        //                 return true;
        //             }

        //             vis[x][y] = -1;
        //         }   
        //     }
        // }
        vis[i][j] = 1;
        bool top = check(i-1,j,index+1,vis,board,word,n,m);
        bool left = check(i,j+1,index+1,vis,board,word,n,m);
        bool right = check(i+1,j,index+1,vis,board,word,n,m);
        bool bottom = check(i,j-1,index+1,vis,board,word,n,m);
        vis[i][j] = -1;
        return top || left || right || bottom;


    }


    bool exist(vector<vector<char>>& board, string word) {


        int index = 0;
        int n = board.size();
        int m = board[0].size();

        // cout<<"n:"<<n<<"m:"<<m;
        for(int i=0; i<n; i++){
            for(int j=0; j< m; j++){
                if(board[i][j] == word[index]){
                    vector<vector<int>> vis(board.size(), vector<int>(board[0].size(), -1));
                    if(check(i,j,index,vis,board,word,n,m)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};