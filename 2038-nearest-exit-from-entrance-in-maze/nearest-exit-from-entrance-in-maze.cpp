class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        queue<pair<int,pair<int,int>>> q;

        int n = maze.size();
        int m = maze[0].size();

        q.push({entrance[0],{entrance[1],0}});

        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};

        vector<vector<int>> vis(n,vector<int>(m,-1));

        cout<<"entrance: {"<<entrance[0]<<","<<entrance[1]<<"}"<<endl;

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int i = it.first;
            int j = it.second.first;
            

            int step = it.second.second;

            // cout<<"{"<<i<<","<<j<<","<<step<<"}"<<endl;
            bool isAtentrance = i==entrance[0] && j==entrance[1];

            if(!isAtentrance && (i==0 || j==0 || i== n-1 || j==m-1)){
                // if(i==0 || j==0 || i== n-1 || j==m-1){
                    return step;
                // }
            }

            for(int k=0; k<4; k++){
                int x = i + dx[k];
                int y = j + dy[k];

                if(x<0 || y<0 || x>=n || y>= m || vis[x][y]==1 || maze[x][y] == '+'){
                    continue;
                }

                vis[x][y] = 1;

                q.push({x,{y,step+1}});

            }
        }

        return  -1;
    }
};