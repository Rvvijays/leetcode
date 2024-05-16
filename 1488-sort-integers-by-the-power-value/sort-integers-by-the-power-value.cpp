class Solution {
public:

    int power(int num) {
        if(num == 1) {
            return 0;
        }


        if(num%2 == 0) {
            return 1 + power(num/2);
        }

        return 1 + power(3*num + 1);
    }
    int getKth(int lo, int hi, int k) {

        vector<pair<int,int>>p;
        for(int i=lo; i<=hi; i++) {
            int pp = power(i);
            p.push_back({pp,i});
        }

        sort(p.begin(), p.end());

        return p[k-1].second;
        
    }
};