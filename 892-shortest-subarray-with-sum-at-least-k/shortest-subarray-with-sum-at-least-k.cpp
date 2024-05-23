class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {

        int left = 0;
        int right = 0;
        int n = nums.size();

        long long prefixSum = 0;

        int mini = INT_MAX;

        deque<pair<long long,int>> q;
        q.push_back({prefixSum,-1});

        for(int i=0; i<n; i++) {
            prefixSum += nums[i];

            while(!q.empty() && q.back().first >= prefixSum){
                q.pop_back();
            }

            int check = prefixSum - k;

            while(!q.empty() && q.front().first <= check) {
                mini = min(mini, i - q.front().second);
                q.pop_front();
            }


            q.push_back({prefixSum,i});


        }

        

        return mini == INT_MAX ? -1 : mini;
    }
};