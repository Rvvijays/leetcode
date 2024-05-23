class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        vector<pair<int,int>> cars;
        for (int i = 0; i < position.size(); i++) {
            cars.push_back({position[i],speed[i]});
        }

        sort(cars.begin(), cars.end());

        stack<pair<int,int>> st;

        for (int i = cars.size()-1; i >= 0; i--) {
            int prevPos = cars[i].first;
            int prevSpeed = cars[i].second;

            double reachTime = (double)(target - prevPos) /(double) prevSpeed;

            

            if(!st.empty()) {

                int nextPos = st.top().first;
                int nextSpeed = st.top().second;


                double nextReachTime =(double) (target - nextPos) / (double)nextSpeed;

                // cout<<"current reachTime: "<<reachTime<<" prevReachTime: "<<nextReachTime<<endl;

                if(reachTime <= nextReachTime){
                    st.pop();
                    st.push({nextPos,min(nextSpeed,prevSpeed)});
                }else{
                    st.push(cars[i]);
                }
            }else{
                st.push(cars[i]);
            }
        }

        return st.size();
    }
};