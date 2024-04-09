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

    int findParent(int node){
        if(node == parent[node]){
            return node;
        }

        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u,int v){
            int pv = findParent(v);
            int pu = findParent(u);

            if(pu == pv){
                return;
            }

            if(size[pu]<size[pv]){
                parent[pu] = pv;
                size[pv] += size[pu];
            }else{
                 parent[pv] = pu;
                size[pu] += size[pv];
            }
        }

};


class Solution {
public:
    int getComponents(int n,vector<vector<int>>& mat){

        DS ds(n);

        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat.size(); j++){
                if(mat[i][j]==1){
                    ds.unionBySize(i,j);
                }
            }
        }
        int comp = 0;
        for(int i=0; i<n; i++){
            if(ds.findParent(i)==i){
                comp++;
            }
        }

        return comp;


    }
    int timer;

    void dfs(int curr, int parent, vector<vector<int>> &list, vector<int> &vis,vector<int> &timeOfInsertion,vector<int> &lowestTime,vector<vector<int>> &ans){
        vis[curr] = 1;
        lowestTime[curr] = timer;
        timeOfInsertion[curr] = timer;
        timer++;

        for(auto adjNode : list[curr]){
            if(adjNode == parent){
                continue;
            }

            if(vis[adjNode]==0){
                dfs(adjNode,curr,list,vis,timeOfInsertion,lowestTime,ans);

                lowestTime[curr] = min(lowestTime[curr], lowestTime[adjNode]);
                if(timeOfInsertion[curr] < lowestTime[adjNode]){
                    ans.push_back({curr,adjNode});
                }
            }else{
                lowestTime[curr] = min(lowestTime[curr], lowestTime[adjNode]);
                
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

        // vector<vector<int>> mat(n,vector<int>(n));
        // for(int i=0; i<connections.size(); i++){
        //     mat[connections[i][0]][connections[i][1]] = 1;
        //     // mat[connections[i][1]][connections[i][0]] = 1;
        // }

        // vector<vector<int>> ans;


        // for(int i=0; i<connections.size(); i++){
        //     // remove connection


        //     mat[connections[i][0]][connections[i][1]] = 0;
        //     // mat[connections[i][1]][connections[i][0]] = 0;

        //     // check components.
        //     int comp = getComponents(n,mat);

        //     mat[connections[i][0]][connections[i][1]] = 1;


        //     if(comp>1){
        //         ans.push_back(connections[i]);
        //     }
        // }

        // return ans;
        // GIVES TIME LIMIT EXCEEDED.


        vector<vector<int>> list(n);
        for(int i=0; i<connections.size(); i++){
           list[connections[i][0]].push_back(connections[i][1]);
           list[connections[i][1]].push_back(connections[i][0]);
        }

        vector<vector<int>> ans;
        vector<int> vis(n,0);
        vector<int> timeOfInsertion(n);
        vector<int> lowestTime(n);

        // for(int i=0; i<n; i++){
        //     if(vis[i]==0){
            dfs(0,-1,list,vis,timeOfInsertion,lowestTime,ans);

        //     }
        // }

        return ans;







        
    }
};