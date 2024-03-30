class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>> list(n+1);

        for(int i=0; i<times.size(); i++){
            list[times[i][0]].push_back({times[i][1],times[i][2]});
        }

        set<pair<int,int>> st;
        vector<int> dist(n+1,INT_MAX);
        st.insert({0,k});

        dist[k] = 0;

        // int maxAns = -1;

        while(!st.empty()){
            auto it = *(st.begin());

            int dis = it.first;
            int node = it.second;
            st.erase(it);

            // cout<<"pop: {"<<dis<<","<<node<<"}"<<endl;

            for(auto ii : list[node]){
                
                int adjNode = ii.first;
                int adjDis = ii.second;

                if(adjDis + dis < dist[adjNode]){
                    // cout<<"push: {"<<adjDis + dis<<","<<adjNode<<"}"<<endl;
                    dist[adjNode] = adjDis + dis;

                    // if(dist[adjNode] > maxAns){
                    //     maxAns = dist[adjNode];
                    // }

                    st.insert({dist[adjNode],adjNode});
                }

            }
        }

        int timeTaken = -1;
        int notReached = 0;
        for(int it : dist) {
            //cout<<it<<" ";

          

            if(it == INT_MAX){
                notReached++;
            }
            if(notReached>1){
                timeTaken = -1;
                break;
            }
            if(it!=INT_MAX && it > timeTaken){
                timeTaken = it;
            }
        }

        return timeTaken;

        

        
    }
};