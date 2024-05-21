// 5 2 5 7 8

class MyStack {
    queue<int> q1;
    queue<int> q2;

public:
    MyStack() {
        
    }
    
    void push(int x) {

        q1.push(x);
        
    }
    
    int pop() {


        int size = q1.size();
        if(size==0){
            return -1;
        }

        for(int i=0; i<size-1; i++) {
            q2.push(q1.front());
            q1.pop();
        }

        int res =  q1.front();
        q1.pop();

        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }

        return res;


        
    }
    
    int top() {
        int size = q1.size();
        if(size==0){
            return -1;
        }

        for(int i=0; i<size-1; i++) {
            q2.push(q1.front());
            q1.pop();
        }

        int res =  q1.front();

        // q
        // q1.pop();
        q2.push(res);
        q1.pop();

        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }

        return res;
        
    }
    
    bool empty() {

        return q1.empty();
        
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */