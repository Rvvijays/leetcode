class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {

        this->k = k;
        for(int i=0; i<nums.size(); i++) {
            pq.push(nums[i]);

           
        }

 while(pq.size() > k) {
                pq.pop();
            }
        
    }
    
    int add(int val) {

        pq.push(val);
       while(pq.size() > k){
        pq.pop()
;       }

        return pq.top();
        
    }
};

// 8 5 4 2

// add 3
// 8 5 4 3 ---> 4
// add 5
// 8 5 5 4 ----> 5
// add 10
// 10 8 5 5 ---> 5
// add 8
// 10 8 8 5 ---> 8

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */