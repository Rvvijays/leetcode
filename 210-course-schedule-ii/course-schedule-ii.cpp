class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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

        vector<int> ans;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto it : list[node]){
                indegree[it]--;

                if(indegree[it]==0){
                    q.push(it);
                }
            }


        }


        if(numCourses == ans.size()){
            return ans;
        }

        return {};


        
    }
};