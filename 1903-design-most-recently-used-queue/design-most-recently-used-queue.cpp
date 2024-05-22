class MRUQueue {
public:
    unordered_map<int,int> mp;
    int size;
    MRUQueue(int n) {
        size = n;

        for(int i=1; i<=n; i++) {
            mp[i] = i;
        }

        // for(auto kk : mp)  {
        //     cout<<kk.first<<" - "<<kk.second<<endl;
        // }

        
    }
    
    int fetch(int k) {

        // cout<<"fetch K:"<<k<<endl;

        int elem = mp[k];

        for(int i=k; i <size; i++) {
            mp[i] = mp[i+1];
        }

        mp[size] = elem;

        //  for(auto kk : mp)  {
        //     cout<<kk.first<<" - "<<kk.second<<endl;
        // }
        return elem;
        
    }
};

/**
 * Your MRUQueue object will be instantiated and called as such:
 * MRUQueue* obj = new MRUQueue(n);
 * int param_1 = obj->fetch(k);
 */