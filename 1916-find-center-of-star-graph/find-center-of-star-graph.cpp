class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {

        int n = edges.size();

        n++;
        // cout<<"n: "<<n<<endl;

        vector<int> indegree(n+1,0);
        // vector<int> outdegree(n+2,0);


        for (int i=0; i<n-1; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            indegree[u]++;
            indegree[v]++;
            // outdegree[u]++;
            // outdegree[v]++;
        }


        // cout<<"indegree: ";
        for (int i=1; i<=n; i++) {
        //    cout<<indegree[i]<<" ";

            if(indegree[i] == n-1) {
                return i;
            }
        }

       

        return -1;
        
    }
};