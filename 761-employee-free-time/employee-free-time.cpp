/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {

        vector<pair<int,int>> intervals;

        for( vector<Interval> t1 : schedule) {
            for(Interval t2 : t1) {
                intervals.push_back({t2.start,t2.end});
            }
        }

        sort(intervals.begin(), intervals.end());

        vector<Interval> ans;

        int maxtl = intervals[0].second;

        for(int i=1; i<intervals.size(); i++) {
            if(maxtl < intervals[i].first) {
                Interval* temp = new Interval(maxtl, intervals[i].first);
                ans.push_back(*temp);
            }

            maxtl = max(maxtl,intervals[i].second);
        }

        return ans;
        
    }
};