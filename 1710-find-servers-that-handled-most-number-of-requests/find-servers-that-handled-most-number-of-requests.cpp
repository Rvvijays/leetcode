class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {

        vector<int> serverFreq(k,0);

        // vector<int> serverStatus(k,0);

        set<int> avaiableServers;
        for (int i=0; i < k; i++) {
            avaiableServers.insert(i);
        }

        
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> inQueue;

        int maxUsed = 0;

        for (int i=0; i<arrival.size(); i++) {
            int start_time = arrival[i];
            long long end_time = start_time + load[i];

            while(!inQueue.empty() && inQueue.top().first <= start_time) {
                int server = inQueue.top().second;
                avaiableServers.insert(server);
                // serverStatus[server] = 0;
                cout<<"server freed: "<<server<<endl;
                inQueue.pop();
            }

            // int needserver = i % k;

            // if(serverStatus[needserver] == 0) {
            //     cout<<"assigned server: "<<needserver<<endl;
            //     inQueue.push({end_time,needserver});
            //     avaiableServers.erase(needserver);
            //     serverFreq[needserver]++;
            //     serverStatus[needserver] = 1;
            //     maxUsed = max(maxUsed, serverFreq[needserver]);

            //     continue;
            // }

            if(avaiableServers.size() > 0) {

                auto ptr = avaiableServers.lower_bound(i%k);
                // int server = *(avaiableServers.begin());
                // cout<<"assigned server: "<<server<<endl;
                if(ptr == avaiableServers.end()) {
                    ptr = avaiableServers.begin();
                }
                int server = *ptr;

                inQueue.push({end_time,server});
                avaiableServers.erase(server);
                serverFreq[server]++;
                // serverStatus[server] = 1;

                maxUsed = max(maxUsed, serverFreq[server]);
            }
        }


        vector<int> ans;

        for(int i=0; i<k; i++) {
            if(serverFreq[i] == maxUsed) {
                ans.push_back(i);
            }
        }

        return ans;
        




    }
};