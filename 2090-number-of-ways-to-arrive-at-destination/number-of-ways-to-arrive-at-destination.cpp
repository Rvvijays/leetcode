#define ll long long 

class Solution {
public:
    void dfs(int node,int currDist, vector<vector<pair<int,int>>> &list, vector<int> &dist,vector<int> &vis,int dest){
        if(node == dest){
            dist.push_back(currDist);
            return;
        }

        vis[node] = 1;

        for(auto it:list[node]){

            int adjNode = it.first;
            int adjDis = it.second;

            if(vis[adjNode]==0){
                dfs(adjNode,currDist+adjDis,list,dist,vis,dest);
            }
        }

        vis[node] = 0;
    }


    int countPaths(int n, vector<vector<int>>& roads) {

        vector<vector<pair<ll,ll>>> list(n);

        for(int i=0; i<roads.size(); i++){
            list[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            list[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }

        // vector<int> dist;
        // vector<int> vis(n,0);
        // dfs(0,0,list,dist,vis,n-1);
        // int min = dist[0];
        // int count = 0;
        // for(int i=0; i<dist.size(); i++){
        //     if(min == dist[i]){
        //         count++;
        //     }
        //     if(dist[i]<min){
        //         min = dist[i];
        //         count = 1;
        //     }
        // }
        // return count;

        // TLE

        vector<ll> dist(n,LLONG_MAX);
        vector<ll> ways(n,0);

        set<pair<ll,ll>> st;
        st.insert({0,0});
        dist[0] = 0;
        ways[0] = 1;

        int mod = (int)(1e9 + 7);

        while(!st.empty()){
            auto it = *(st.begin());

            ll node = it.second;
            ll dis = it.first;

            st.erase(it);

            for(auto ii : list[node]){

                ll adjNode = ii.first;
                ll adjDis = ii.second;


                if(adjDis + dis < dist[adjNode]){
                    dist[adjNode] = adjDis + dis;
                    ways[adjNode] =  ways[node];
                    st.insert({dist[adjNode],adjNode});
                }else if(adjDis + dis == dist[adjNode]){
                    ways[adjNode] = (ways[node] + ways[adjNode]) % (mod);

                }

               
            }
        }

        return ways[n-1] % mod;




        
    }
};