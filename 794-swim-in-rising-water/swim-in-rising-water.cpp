class Solution {
public:

    void dfs(int i,int j, int n, vector<int> time, vector<int>& ans, vector<vector<int>>& grid,vector<vector<int>>& vis){

        vis[i][j] = 1;
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        cout<<"time:"<<time[0]<<endl;
        int minTime = INT_MAX;
        int minx = i;
        int miny = j;

        for(int k=0; k<4; k++){
            int x = i + dx[k];
            int y = j + dy[k];
            if(x<0 || y <0 || x>= n || y>= n || vis[x][y]==1 ){
                continue;
            }
            if(x == n-1 && y ==n-1){
                if(grid[x][y]>time[0]){
                    time[0] = grid[x][y];
                }
                ans[0] = min(time[0],ans[0]);
               return;
            }
            cout<<"time:"<<time[0]<<" node:"<<grid[x][y]<<endl;
            int oldTime = time[0];
            time[0] = grid[x][y]<time[0]?time[0]:grid[x][y];
            dfs(x,y,n,time,ans,grid,vis);
            time[0] = oldTime;
        }

    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        set<pair<int,pair<int,int>>> st;
        
        st.insert({grid[0][0],{0,0}});
        vector<vector<int>> vis(n,vector<int>(n,0));
        vis[0][0] = 1;

        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};

        int ans = INT_MAX;

        while(!st.empty()){
            auto it = *(st.begin());

            int time = it.first;
            int i = it.second.first;
            int j = it.second.second;


            if(i == n-1 && j == n-1){
                ans = min(time,ans);
                
            }

            st.erase(it);

            for(int k=0; k<4; k++){
                int x = i + dx[k];
                int y = j + dy[k];

                if(x < 0 || y < 0 || x >= n || y >= n || vis[x][y]==1){
                    continue;
                }

                vis[x][y] = 1;
                int newTime = time >= grid[x][y] ? time : grid[x][y];
                st.insert({newTime,{x,y}});
            }


        }
       

       return ans;

    }
};