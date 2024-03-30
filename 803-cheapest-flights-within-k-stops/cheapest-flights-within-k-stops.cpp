class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<pair<int,int>>> list(n);

        for(int i=0; i<flights.size(); i++){
            // cout<<"u:"<<flights[i][0]<<" v:"<<flights[i][1]<<" cost:"<<flights[i][2]<<endl;
            list[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }


        vector<int> dist(n,INT_MAX);
        set<pair<int,pair<int,int>>> st;
        // vector<int> temp(n,INT_MAX);

        st.insert({0,{0,src}});
        dist[src] = 0;

        while(!st.empty()){
            auto it = *(st.begin());
           

            int stop = it.first;
            int cost = it.second.first;
            int node = it.second.second;
            st.erase(it);

            // cout<<"pop: {"<<cost<<",{"<<node<<","<<stop<<"}}"<<endl;

            if(stop > k){
                // cout<<"yha aaya.."<<endl;
                // if(dist[node]> cost){
                //     dist[node] = cost;

                // }
            
                continue;
            }

            
          
            // cout<<"adjacent:"<<endl;

            for(auto ii : list[node]){
                int adjNode = ii.first;
                int adjCost = ii.second;

                // cout<<"node: "<<adjNode<<" cost:"<<adjCost<<endl;

                // cout<<"newCost:"<< cost + adjCost<<" oldCost:"<<dist[adjNode]<<endl;

                if(cost + adjCost < dist[adjNode]){
                    // cout<<"inserting:"<<endl;
                    // temp[adjNode] = cost+adjCost;
                        dist[adjNode] = cost+adjCost;
                    // cout<<"node: "<<adjNode<<" cost:"<<temp[adjNode]<<" stop:"<<stop+1<<endl;
                    // cout<<"push: {"<<temp[adjNode]<<",{"<<adjNode<<","<<stop+1<<"}}"<<endl;

                    // if(stop <= k){
                    st.insert({stop+1,{dist[adjNode],adjNode}});

                    // }
                }
            }
        }

        return dist[dst]==INT_MAX?-1:dist[dst];

        
    }
};