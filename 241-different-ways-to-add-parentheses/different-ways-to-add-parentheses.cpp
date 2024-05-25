class Solution {
public:
    vector<int> recursion(int low, int high, string s) {

        vector<int> ans;
        if (low == high) {
            // cout<<"returned: "<<(s[low]-'0')<<endl;
            ans.push_back(s[low] - '0');
            return ans;
        }
        int num = 0;
        bool operatorfound = false;
        for (int i = low; i <= high; i++) {
            char ch = s[i];

            if (ch == '*' || ch == '+' || ch == '-') {
                operatorfound = true;
                num = 0;
                vector<int> left = recursion(low, i - 1, s);
                vector<int> right = recursion(i + 1, high, s);

                for (auto leftl : left) {
                    for (auto rightl : right) {
                        int temp = (ch == '*')
                                       ? (leftl * rightl)
                                       : ((ch == '+') ? (leftl + rightl)
                                                      : (leftl - rightl));

                                                    //   cout<<"temp:"<<temp<<endl;
                        ans.push_back(temp);
                    }
                }
            }else{
                num = num * 10 + (ch - '0');
            }
        }
        if(!operatorfound && num > 0) {
            ans.push_back(num);
        }

        return ans;
    }
    vector<int> diffWaysToCompute(string expression) {

        return recursion(0, expression.size()-1, expression);
    }
};