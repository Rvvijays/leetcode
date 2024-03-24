class Solution {
public:

    void dfs(int i, int j, int n, int m, vector<vector<int>>& grid){
        grid[i][j] = 0;

        vector<int> dx = {0,0,1,-1};
        vector<int> dy = {1,-1,0,0};

        for(int k=0; k<4; k++){
            int nx = i + dx[k];
            int ny = j + dy[k];

            if( nx < 0 || ny <0 || nx >= n || ny >= m || grid[nx][ny]==0){
                continue;
            }

            dfs(nx,ny,n,m,grid);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();



        for(int i=0; i<n; i++){

            if(grid[i][0] == 1){
                dfs(i,0,n,m,grid);
            }

            if(grid[i][m-1] == 1){
                dfs(i,m-1,n,m,grid);
            }

        }

        for(int i=0; i<m; i++){
             if(grid[0][i] == 1){
                dfs(0,i,n,m,grid);
            }

            if(grid[n-1][i] == 1){
                dfs(n-1,i,n,m,grid);
            }
        }

        int count=0;

        for(int i=0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1){
                    count++;
                }
            }
        }

        return count;
        
    }
};