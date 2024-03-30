class Solution {
public:

  
    int minimumEffortPath(vector<vector<int>>& heights) {


        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));

        dist[0][0] = 0;

        set<pair<int,pair<int,int>>> st;
        st.insert({0,{0,0}});

        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};

        while(!st.empty()){
            auto it = *(st.begin());
            st.erase(it);

            int dis = it.first;
            int i = it.second.first;
            int j = it.second.second;

            // cout<<"popped: {"<<dis<<",{"<<i<<","<<j<<"}}"<<endl;
            // cout<<"edges:"<<endl;

            for(int k=0; k<4; k++){
                int x = i + dx[k];
                int y = j + dy[k];

                if(x < 0 || y < 0 || x >= n || y >= m){
                    continue;
                }

                

                int newDis = max(abs(heights[i][j] - heights[x][y]),dis);

                // cout<<"{"<<newDis<<",{"<<x<<","<<y<<"}}"<<endl;

                if(newDis < dist[x][y]){
                    // cout<<"pushed: {"<<newDis<<",{"<<x<<","<<y<<"}}"<<endl;
                    dist[x][y] = newDis;
                    st.insert({newDis,{x,y}});
                }
            }
        }

        return dist[n-1][m-1];
        
    }
};