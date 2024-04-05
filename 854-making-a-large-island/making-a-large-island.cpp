void dfs(int i,int j, int n, int m, vector<vector<int>>& grid, vector<vector<int>>& vis, vector<int> &ans) {
    vis[i][j] = 1;
    ans[0]++;

    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};


    for(int k=0; k<4; k++){
        int x = i + dx[k];
        int y = j + dy[k];

        if(x < 0 || y <0 || x >= n || y >= m || vis[x][y]==1 || grid[x][y]==0){
            continue;
        }

        dfs(x,y,n,m,grid,vis,ans);
    }


}

class DS{
    vector<int> parent,size;

    public:
    DS(int n){
        parent.resize(n);
        size.resize(n,1);

        for(int i=0; i<n; i++){
            parent[i] = i;
        }
    }

    int getSize(int node){
        return size[node];
    }

    int findParent(int node){
        if(node == parent[node]){
            return node;
        }

        return parent[node] = findParent(parent[node]);
    }

    void print(){
        for(int i=0; i<size.size(); i++){
            cout<<i<<": "<<size[i]<<", ";
        }
    }


    void unionBySize(int u, int v){
        int pv = findParent(v);
        int pu = findParent(u);

        if(pu == pv){
            return;
        }

        if (size[pv] < size[pu]) {
            parent[pv] = pu;
            size[pu] += size[pv];
        } else {
            parent[pu] = pv;
            size[pv] += size[pu];
        }


    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // vector<int> ans(1,0);

        // int area = -1;

        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         if(grid[i][j]==0){
        //             grid[i][j] = 1;
        //             vector<vector<int>> vis(n,vector<int>(m,0));
        //             ans[0] = 0;

        //             dfs(i,j,n,m,grid,vis,ans);
        //             grid[i][j] = 0;

        //             area = max(area,ans[0]);
        //         }
        //     }
        // }

        DS ds(n*m);
        // cout<<"n:"<<n<<" m:"<<m<<endl;

        // cout<<"nodes:"<<n*m<<endl;

        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        // vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){

                if(grid[i][j] == 1){
                    int node = i*m+j;
                    // cout<<"i:"<<i<<" j:"<<j<<endl;
                    // cout<<"node:"<<node<<endl;
                    for(int k=0; k<4; k++){
                        int x = i + dx[k];
                        int y = j + dy[k];
                        // cout<<"px:"<<x<<" py:"<<y<<endl;
                        if (x < 0 || y < 0 || x >= n || y >= m || grid[x][y] == 0 ) {
                            continue;
                        }
                        // cout<<"x:"<<x<<" y:"<<y<<endl;
                        int adjNode = x*m + y;
                        //cout<<"adjacentNode:"<<adjNode<<endl;
                        // if(ds.findParent(node)!=ds.findParent(adjNode)){
                            // cout<<"connected: u:"<<node<<" v:"<<adjNode<<endl;
                            ds.unionBySize(node,adjNode);
                        // }
                        // cout<<" joinng u:"<<node<<" v:"<<adjNode<<endl;
                    }
                }
                

            }
        }


        // cout<<"size array:";
        // ds.print();
        // cout<<endl;


        int area = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 0) {
                    set<int> parents;
                    for(int k=0; k<4; k++){
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if (x < 0 || y < 0 || x >= n || y >= m || grid[x][y]==0) {
                            continue;
                        }
                        

                        int node = x*m + y;
                        int pv = ds.findParent(node);
                        // cout<<"adding with pv:"<<pv<<endl;
                        parents.insert(pv);
                        // size += ds.getSize(pv);
                    
                    }

                    int size = 1;
                    while(!parents.empty()){
                        int node = *(parents.begin());
                        //cout<<"componenet parent:"<<node<<endl;
                        parents.erase(node);
                        size +=ds.getSize(node);
                    }

                    area = max(area,size);
                }
            }
        }

        for(int i=0; i<n*m; i++){
            area = max(ds.getSize(i),area);
        }



        return area;

    }
};