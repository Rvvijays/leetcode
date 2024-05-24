class Solution {
public:
    int calculate(string s) {

        stack<int> st;

        int number = 0;
        int result = 0;
        int sign = 1;
        for (int i = 0; i < s.length(); i++) {

            char ch = s[i];

            
        

            cout << "char: " << ch << endl;

            if (isdigit(ch)) {
                number = (number * 10) + (ch - '0');
            } else if (ch == '+' || ch == '-') {
                // cout<<"sign:"<<ch<<endl;
                result += number * sign;
                number = 0;
                sign = ch == '+' ? 1 : -1;
            } else if (ch == '(') {
                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1;
            } else if(ch == ')'){
                result += number * sign;
                number = 0;

                result *= st.top();
                st.pop();
                result += st.top();
                st.pop();
                sign = 1;
            }

            // if(number > 0) {
            // }

                // cout << "number: " << number << endl;
                // cout<<"result: "<<result<<endl;
                // cout<<"sign: "<<sign<<endl;



        }

                result += number * sign;

        return result;
    }
};