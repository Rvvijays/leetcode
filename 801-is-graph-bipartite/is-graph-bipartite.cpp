class Solution {
public:

    bool dfs(int node, int color, vector<vector<int>>& graph, vector<int> &vis){

        vis[node] = color;

        for(auto it: graph[node]){
            if(vis[it]!=-1 && vis[it]==color){
                return false;
            }

            if(vis[it]==-1){
                if(dfs(it,!color,graph,vis) == false){
                    return false;
                }
            }
        }
        
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();

        vector<int> vis(n,-1);
        int color = 0;

        // vis[0] = color;
        // cout<<"node 0:0"<<endl;

        for(int i=0; i<n; i++){
            if(vis[i]==-1){
                if(dfs(i,color,graph,vis)==false){
                    return false;
                }
            }
        }

        return true;

        
    }
};