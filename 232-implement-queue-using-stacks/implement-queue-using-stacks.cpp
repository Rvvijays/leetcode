class MyQueue {
    stack<int> st1;
    stack<int> st2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {

        while(!st2.empty()) {
                st1.push(st2.top());
                st2.pop();
            }

        st1.push(x);
    }
    
    int pop() {

        if(st1.empty() && st2.empty()){
            return -1;
        }


        while(!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }

        int res = st2.top();
        st2.pop();

        // while(!st2.empty()) {
        //     st1.push(st2.top());
        //     st2.pop();
        // }

        return res;
        
    }
    
    int peek() {

       
        if(st1.empty() && st2.empty()){
            return -1;
        }


        while(!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }

        int res = st2.top();
        // st2.pop();


        return res;
        
    }
    
    bool empty() {

        return st1.empty() && st2.empty();
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */