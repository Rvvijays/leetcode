class Solution {
public:
    void dfs(int curr, int time, vector<vector<int>> &adjList, vector<int>& informTime, int &maxi) {
        maxi = max(maxi,time);

        for(int adjNode : adjList[curr]) {
            dfs(adjNode,time+informTime[curr],adjList, informTime,maxi);
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {

        vector<vector<int>> list(n);

        for(int i=0; i<manager.size(); i++) {
            if(manager[i]!=-1) {
                list[manager[i]].push_back(i);
            }
        }

        int maxi = INT_MIN;

        dfs(headID,0,list,informTime,maxi);

        return maxi;
        
    }
};