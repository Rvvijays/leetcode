class Solution {
public:

    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        set<pair<int,pair<int,int>>> st;

        st.insert({0,{0,0}});

        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};

        vector<vector<int>> dis(n,vector<int>(m,1e9));

        dis[0][0] = 0;


        while(!st.empty()) {
            auto it = *(st.begin());
            st.erase(it);

            int cost = it.first;
            int x = it.second.first;
            int y = it.second.second;

            // if(x == n-1 && y == m-1){
            //     return cost;
            // }

            for(int k=0; k<4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if(nx <0 || ny <0 || nx >= n || ny >= m ){
                    continue;
                }


                int wt = grid[nx][ny];

                if(dis[nx][ny] > wt + cost) {
                    dis[nx][ny] = wt + cost;
                 st.insert({ dis[nx][ny],{nx,ny}});

                }


            }




        }

        return dis[n-1][m-1];


    
    }
};