class Solution {
public:

    void dfs(int node, vector<vector<int>> &list, vector<int> &vis){
        vis[node] = 1;

        for(int i=0; i<list[node].size(); i++){
            if(list[node][i] == 1 && vis[i]!=1){
                dfs(i,list,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();

        vector<int> vis(n,0);

        int count = 0;

        for(int i=0; i<n; i++){
            if(vis[i]!=1){
                dfs(i,isConnected,vis);
                count++;
            }
        }

        return count;

        
    }
};