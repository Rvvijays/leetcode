class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();        
        queue<pair<int,int>> q;

        int totalOranges = 0;
        int totalRotten = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]!=0){
                    totalOranges++;
                }
            }
        }

        vector<int> dx = {0,0,1,-1};
        vector<int> dy = {1,-1,0,0};

        int totalTime = 0;
        // cout<<"totalRotten:"<<totalRotten<<endl;
        // cout<<"totalOranges:"<<totalOranges<<endl;




        while(!q.empty()){

            int k = q.size();
            totalRotten += k;

            while(k--){
                auto node = q.front();
                q.pop();

                for(int i=0; i<4; i++){
                    int x = node.first + dx[i];
                    int y = node.second + dy[i];

                    if(x < 0 || y <0 || x >= n || y >= m || grid[x][y]!=1){
                        continue;
                    }

                    grid[x][y] = 2;
                    q.push({x,y});
                    
                }

            }

            if(!q.empty()){
                totalTime++;
            }
        


        }

        if(totalOranges == totalRotten){
            return totalTime;
        }

        return -1;

        
    }
};