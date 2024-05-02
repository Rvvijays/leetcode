class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int index = 0;
        int n = s.size();

        while(index <n){
            if(s[index] == '('){
                st.push(s[index]);
            }else{
                if(!st.empty() && st.top() == '('){
                    st.pop();
                }else{
                    st.push(')');
                }
            }

            index++;
        }

        return st.size();
    }
};