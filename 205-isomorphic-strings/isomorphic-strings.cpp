/*
s = "paper", t = "title"

p -> t
a -> i
p -> t

*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        int n = s.size();
        int m = t.size();
        
        if (n != m) {
            return false;
        }
        
        unordered_map<char,char> mp_st;
        unordered_map<char,char> mp_ts;
        
        for (int i = 0; i < n; i++) {
            char a = s[i];
            char b = t[i];

            if (mp_st.find(a) == mp_st.end() && mp_ts.find(b)==mp_ts.end()){
                mp_st[a] = b;
                mp_ts[b] = a;
            }else if(mp_st.find(a)!=mp_st.end() && mp_ts.find(b)!=mp_ts.end()){
                if(mp_st[a] != b || mp_ts[b]!=a){
                    return false;
                }
            }else{
                return false;
            }


            
        }
        
        return true;
        
    }
};