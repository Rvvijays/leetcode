class StockPrice {
    unordered_map<int,int> mp;
    int currentTime = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minPq;
    priority_queue<pair<int,int>> maxPq;


public:
    StockPrice() {

        
        
    }
    
    void update(int timestamp, int price) {
        currentTime = max(timestamp,currentTime);
        mp[timestamp] = price;
        maxPq.push({price,timestamp});
        minPq.push({price,timestamp});

        
    }
    
    int current() {

        return mp[currentTime];

        
    }
    
    int maximum() {

        if(!maxPq.empty()) {
            auto top = maxPq.top();

            while(mp[top.second] != top.first) {
                maxPq.pop();
                maxPq.push({mp[top.second],top.second});
                top = maxPq.top();
            }

            return top.first;
        }

        return -1;
        
    }
    
    int minimum() {
         if(!minPq.empty()) {
            auto top = minPq.top();

            while(mp[top.second] != top.first) {
                minPq.pop();
                minPq.push({mp[top.second],top.second});
                top = minPq.top();
            }

            return top.first;
        }

        return -1;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */