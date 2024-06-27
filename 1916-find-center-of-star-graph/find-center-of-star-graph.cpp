class Solution {
public:

    int brute(vector<vector<int>>& edges) {
        int n = edges.size();

        n++;

        vector<int> indegree(n+1,0);


        for (int i=0; i<n-1; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            indegree[u]++;
            indegree[v]++;

            if(indegree[u] == n-1) {
                return u;
            }

             if(indegree[v] == n-1) {
                return v;
            }



        }

        return -1;
    }
    int findCenter(vector<vector<int>>& edges) {

        int first = -1;
        int second = -1;
        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            if (first == -1) {
                first = u;
                second = v;
                continue;
            }

            first = first == u ? u : v;
            second = second == v ? v : u;
        }


        return first;

        
        
    }
};