class Solution {
public:

    void dfs(int node, vector<vector<int>> &list, vector<int> &vis, stack<int> &st){
        vis[node] = 1;

        for(auto it : list[node]){
            if(!vis[it]){
                dfs(it,list,vis,st);
            }
        }

        st.push(node);
    }

    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> list(numCourses);
        vector<int> indegree(numCourses,0);

        for(auto it : prerequisites) {
            list[it[1]].push_back(it[0]);
        }

        for(int i=0; i<numCourses; i++){
            for(auto it : list[i]){
                indegree[it]++;
            }
        }

        queue<int> q;
    
        for(int i=0; i<indegree.size(); i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        int ans = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans++;

            for(auto it : list[node]){
                indegree[it]--;

                if(indegree[it]==0){
                    q.push(it);
                }
            }


        }

        cout<<"totp:"<<q.size();

        if(numCourses == ans){
            return true;
        }

        return false;




        
    }
};