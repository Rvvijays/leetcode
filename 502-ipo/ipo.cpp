class Solution {
public:

    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {

        int n = profits.size();
        vector<pair<int,int>> capProfit(n);

        for (int i = 0; i < n; i++) {
            capProfit[i] = {capital[i],profits[i]};
        }

        sort(capProfit.begin(), capProfit.end());


        priority_queue<int> pq;


        // int ans = 0;

        int i=0;
        while (k>0) {
            // cout<<"capital: "<<w<<endl;
            while(i < n && capProfit[i].first <= w) {
                // cout<<"capital: "<<w<<endl;
                // cout<<" added: "<<capProfit[i].second<<endl;
                pq.push(capProfit[i].second);
                // cout<<"index: "<<i<<" push: "<<capProfit[i].second<<endl;
                i++;
            }

            if(pq.empty()) {
                break;
            }

            if(!pq.empty()) {
                // ans += pq.top();
                // cout<<"added to anser:"<<pq.top()<<endl;
                w += pq.top();
                // cout<<"pop: "<<pq.top()<<endl;
                pq.pop();
                k--;
            }

            
        }

        return w;
    

    }
};