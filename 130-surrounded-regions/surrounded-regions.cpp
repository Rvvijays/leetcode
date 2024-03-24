class Solution {
public:

    void dfs(int i, int j,int n, int m, vector<vector<char>>& board,vector<vector<int>> &vis){
        // if(i < 0 || j < 0 || i >= n || j >= m){
        //     return;
        // }

        // cout<<"visited:"<<i<<" "<<j<<endl;
        vis[i][j] = 1;

        vector<int> dx = {0,0,1,-1};
        vector<int> dy = {1,-1,0,0};

        for(int k=0; k<4; k++){
            int nx = i + dx[k];
            int ny = j + dy[k];

            //cout<<"("<<nx<<","<<ny<<")"<<endl;

            if(nx < 0 || ny < 0 || nx >= n || ny >= m || vis[nx][ny]==1 || board[nx][ny]=='X'){
               continue;
            }

            dfs(nx,ny,n,m,board,vis);
        }
        
    }

    // void bfs(int i, int j, int n, int m, vector<vector<char>>& board,vector<vector<char>>& vis){

    //     queue<
    //     vis[i][j] = 1;

    //     vector<int> dx = {0,0,1,-1};
    //     vector<int> dy = {1,-1,0,0};


        

    // }
    void solve(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i=0; i<n; i++){

           
            if(board[i][0] == 'O'){
                dfs(i,0,n,m,board,vis);

            }

           

            if(board[i][m-1] == 'O'){
                dfs(i,m-1,n,m,board,vis);
            }
        }

        for(int i=0; i<m; i++){
             if(board[0][i] == 'O'){
                dfs(0,i,n,m,board,vis);

            }
             if(board[n-1][i] == 'O'){
                dfs(n-1,i,n,m,board,vis);

            }

        }



        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout<<vis[i][j]<<" ";
                if(vis[i][j] == 0){
                    board[i][j] = 'X';
                }
            }
            cout<<endl;
        }
    }
};