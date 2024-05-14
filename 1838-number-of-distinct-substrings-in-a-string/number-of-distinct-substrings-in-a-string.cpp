class Solution {
public:

  
    int countDistinct(string s) {
        set<string> st;
        for (int i = 0; i<s.size(); i++) {
            string str = "";
            for(int j = i; j<s.size(); j++) {
                str += s[j];
                st.insert(str);
            }
        }

        return st.size();
    }
};