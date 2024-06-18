class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> diff;
        int n = profit.size();

        for (int i=0; i<n; i++) {
            diff.push_back({difficulty[i],i});
        }

        sort(diff.begin(), diff.end());
        sort(worker.begin(), worker.end());

        int diffIndex = 0;

        int maxDiff  = 0;

        // priority_queue<int> pq;
        int maxi = 0;
        int ans = 0;

        for(int i=0; i<worker.size(); i++) {
            
            while(diffIndex < n && diff[diffIndex].first <= worker[i]) {
                maxi = max(maxi, profit[diff[diffIndex].second]);
                diffIndex++;
            }

            // if(!pq.empty()) {
                ans += maxi;
            // }


        }

        return ans;
      
    }
};