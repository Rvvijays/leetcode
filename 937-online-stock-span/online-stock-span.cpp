class StockSpanner {
    vector<int> arr;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        arr.push_back(price);

        int n = arr.size();
        int count = 0;
        while(n>0 && arr[n-1] <= price) {
            count++;
            n--;
        }

        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */