class MyCalendar {
    vector<pair<int,int>> events;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {

        for(int i=0; i<events.size(); i++) {

            int present_event_start_time = events[i].first;
            int present_event_end_time = events[i].second;

            if(start < present_event_end_time && present_event_start_time < end) {
                return false;
            }
           
        }

        // pair<int,int> event{start,end};

        // auto nextEvent = events.lower_bound(event);

        // if(nextEvent != events.end() && nextEvent->first < end) {
        //     return false;
        // }

        // if(nextEvent != calendar.begin()) {

        // }

        events.push_back({start,end});
        return true;
        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */