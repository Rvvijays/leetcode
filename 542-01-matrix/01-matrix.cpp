class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> ans(n,vector<int>(m,0));

        queue<pair<pair<int,int>,int>> q;

       

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0) {
                    q.push({{i,j},0});
                    vis[i][j] = 1;

                }
            }
        }

        vector<int> dx = {0,0,1,-1};
        vector<int> dy = {1,-1,0,0};

        while(!q.empty()){

            int k = q.size();

            while(k--){
                auto node = q.front();
                q.pop();

                int x = node.first.first;
                int y = node.first.second;
                int step = node.second;

                ans[x][y] = step;

                for(int i=0; i<4; i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if(nx<0 || ny <0 || nx >= n || ny >= m || vis[nx][ny]!=0){
                        continue;
                    }

                    q.push({{nx,ny},step+1});
                    vis[nx][ny] = 1;


                }


            }

        }

        return ans;
        
    }
};