class Solution {
public:

    bool isCycle(int node,vector<vector<int>>& graph,vector<int> &vis, vector<int> &pathVis,vector<int> &check){
        vis[node] = 1;
        pathVis[node] = 1;
        check[node]= 0;

        for(auto it: graph[node]){
            if(vis[it]==0){

                
                
                if (isCycle(it,graph,vis,pathVis,check)){
                    check[node] = 0;
                    return true;
                }
            }else if(vis[it]!=0 && pathVis[it]!=0){
                check[node] = 0;
                return true;
            }
        }

        pathVis[node] = 0;
        check[node] = 1;
        return false;


    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        // vector<int> vis(graph.size(),0);
        // vector<int> pathVis(graph.size(),0);
        // vector<int> check(graph.size(),0);

        // for(int i=0; i<graph.size(); i++){
        //     if(vis[i]==0){
        //         isCycle(i,graph,vis,pathVis,check);
        //     }
        // }

        // vector<int> ans;
        // for(int i=0; i<graph.size(); i++){
        //     if(check[i]==1){
        //         ans.push_back(i);
        //     }

        // }

        // return ans;

        // BFS se

        vector<vector<int>> list(graph.size());
        vector<int> indegree(graph.size(),0);

        for(int i=0; i<graph.size(); i++){
            for(auto it : graph[i]){
                list[it].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        for(int i=0; i<graph.size(); i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto it:list[node]){
                indegree[it]--;

                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }

        sort(ans.begin(),ans.end());

        return ans;











    }
};