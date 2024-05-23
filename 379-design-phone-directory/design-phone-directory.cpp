class PhoneDirectory {
    vector<int> dir;
    int size;
public:
    PhoneDirectory(int maxNumbers) {
        size = maxNumbers;
        dir.resize(maxNumbers);
        for(int i=0; i<maxNumbers; i++) {
            dir[i] = 0;
        }
        
    }
    
    int get() {

        for(int i=0; i<size; i++) {
            if(dir[i]==0){
                dir[i] = 1;
                return i;
            }
        }

        return -1;
        
    }
    
    bool check(int number) {

        return !dir[number];
        
    }
    
    void release(int number) {
        dir[number] = 0;
        
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */