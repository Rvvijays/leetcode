class Solution {
public:
    string removeKdigits(string num, int k) {

        // if(num.length() == 1 && k >= 1) {
        //     return "0";
        // } 

        string ans;

        for(int i=0; i<num.length(); i++) {

            while(k>0 && ans.length()>0 && ans.back()-'0' > num[i] - '0') {
                cout<<"poped:"<<ans.back()<<endl;
               ans.pop_back();
               k--;
            }

            if(ans.length() == 1 && ans.back() == '0') {
                ans.pop_back();
            }

           

            cout<<"added: "<<num[i]<<endl;
            ans += num[i];

        }

        while(k > 0 && ans.length() > 0) {
            ans.pop_back();
            k--;
        }

        if(ans == "" ) {
            ans = "0";
        }

        return ans;
        
    }
};