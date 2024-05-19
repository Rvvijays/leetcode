class Solution {
public:
    
    void dfs(int i,int j, int n,int m, vector<vector<char>>& grid, vector<vector<int>>& vis){
        vis[i][j] = 1;
        
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        
        for(int k=0; k<4; k++){
            int x = i + dx[k];
            int y = j + dy[k];
            
            if(x<0 || y<0 || x>=n || y >=m || vis[x][y] == 1 || grid[x][y] == '0'){
                continue;
            }
            
            dfs(x,y,n,m,grid,vis);
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1' && vis[i][j]==0){
                    dfs(i,j,n,m,grid,vis);
                    count++;
                }
            }
        }
        
        return count;
        
        
    }
};