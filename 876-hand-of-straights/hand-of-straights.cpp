class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        int n = hand.size();

        if(n % groupSize != 0) {
            return false;
        }

        map<int,int> hash;
        // vector<int> hash(hand.size()+1, 0);

        for (int i=0; i<hand.size(); i++) {
            hash[hand[i]]++;
        }


        while(hash.size() > 0) {
            auto it = *(hash.begin());

            cout<<"from map: "<<it.first<<endl;
            
            // for (auto it : hash) {
                
                for(int i=it.first; i<it.first + groupSize; i++) {
                    if(hash.find(i) == hash.end()) {
                        return false;
                    }

                    cout<<"found: "<<i<<endl; 
                    hash[i]--;

                    if(hash[i]==0) {
                        hash.erase(i);
                    }
                }
                
            // }
        }

        return true;


        
    }
};