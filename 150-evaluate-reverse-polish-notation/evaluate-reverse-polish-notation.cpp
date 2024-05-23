class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int> st;

        for(int i=0; i<tokens.size(); i++) {

            if(tokens[i] == "*" || tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "/") {
                 int num2 = st.top(); st.pop();
                int num1 = st.top(); st.pop();

                if(tokens[i] == "+") {
                    num1 += num2;
                }else if(tokens[i] == "-") {
                    num1 -= num2;
                }else if(tokens[i] == "*") {
                    num1 *= num2;
                }else {
                    num1 /= num2;
                }

                st.push(num1);
            }else{
                st.push(stoi(tokens[i]));
               
            }
        }

        return st.top();
        
    }
};