class Solution {
public:
    int visibleMountains(vector<vector<int>>& peaks) {

        vector<vector<int>> intervals;

        if(peaks.size() == 1){
            return 1;
        }

        for(auto peak : peaks) {
            intervals.push_back({peak[0] - peak[1],peak[0]+peak[1]});
        }

        sort(intervals.begin(), intervals.end());

    

        int ans = 0;
        int i = 0;

        while( i <intervals.size()) {
            ans++;

            if(i == intervals.size() -1) {
                return ans;
            }

            int high = intervals[i][1];
            if(intervals[i][0] == intervals[i+1][0]) {
                ans--;
            }

            while(i+1 != intervals.size() && high >= intervals[i+1][1]) {
                i++;
            }

            i++;
        }

        return ans;

        

        
    }
};