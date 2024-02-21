class Solution {
public:

    bool isValid(string s){
        stack<char> st;
        // st.push('#');
        int len = 0;
        // cout<<"checking:"<<s;

        while(len<s.length()){
            // cout<<"checking:"<<len;

            char c = s[len];
            // cout<<"char:"<<c;
            if(c == '('){
                // cout<<"ye chala";
                st.push(s[len]);
                // cout<<"ye chlaa ke baad";
            }else{
                if(!st.empty()){
                st.pop();
                }
                
            }

           len++;
        }

        // cout<<"yhaa aaya";
       return st.empty();

    }

    void generate(string curr,int openCount, int closeCount,vector<string> &ans,int n){

        if(curr.length() == n*2){
            if(isValid(curr)){
                ans.push_back(curr);

            }
            return;
        }

        if(openCount <n && closeCount<n){
            generate(curr+"(",openCount+1,closeCount,ans,n);
            generate(curr+")",openCount,closeCount+1,ans,n);
        }else if(openCount<n){
            generate(curr+"(",openCount+1,closeCount,ans,n);
        }else{
             generate(curr+")",openCount,closeCount+1,ans,n);
        }
        
    }
    vector<string> generateParenthesis(int n) {

        vector<string> ans;

        // string s = "()))((";

        // if(isValid(s)){
        // cout<<"valid:";

        // }else{
        // cout<<"invalid:";

        // }


       generate("(",1,0,ans,n);

        return ans;
        
    }
};