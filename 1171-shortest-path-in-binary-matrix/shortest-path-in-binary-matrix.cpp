class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        if(grid[0][0]!=0){
            return -1;
        }

        int n = grid.size();

        vector<vector<int>> dist(n,vector<int>(n,1e9));

        dist[0][0] = 1;

        set<pair<int,pair<int,int>>> st;
        st.insert({1,{0,0}});

        int dx[8] = {0,0,1,-1,1,1,-1,-1};
        int dy[8] = {1,-1,0,0,1,-1,-1,1};

        while(!st.empty()){
            auto it = *(st.begin());
            int dis = it.first;
            int i = it.second.first;
            int j = it.second.second;
            st.erase(it);

            // cout<<"set: {"<<dis<<",{"<<i<<","<<j<<"}}"<<endl;

            for(int k=0; k<8; k++){
                int x = i + dx[k];
                int y = j + dy[k];
                // cout<<"checking: {"<<x<<","<<y<<"}"<<endl;

                if(x < 0 || y < 0 || x >= n || y >= n || grid[x][y]==1){
                    continue;
                }


                if(dis + 1 < dist[x][y]) {
                    dist[x][y] = dis + 1;

                    st.insert({dis+1,{x,y}});
                }
            }


        }


        return dist[n-1][n-1]==1e9?-1:dist[n-1][n-1];
        
    }
};