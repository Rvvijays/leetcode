class Solution {
public:
    string addBinary(string a, string b) {

        int n = a.length();
        int m = b.length();

        if(n>m){
            return addBinary(b,a);
        }

        string ans = "";

        int carry = 0;

        int i = 0;
        int j = 0;

        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());

        while(i<n){
            if(carry == 1){

                if(a[i] == '1' && b[j] == '1'){
                    carry = 1;
                    ans += '1';
                }else if((a[i]=='1' && b[j] == '0') ||(a[i]=='0' && b[j] == '1') ){
                    carry = 1;
                    ans += '0';
                }else{
                    carry = '0';
                    ans += '1';
                }

            }else{
                if(a[i] == '1' && b[j] == '1'){
                    carry = 1;
                    ans += '0';
                }else if((a[i]=='1' && b[j] == '0') ||(a[i]=='0' && b[j] == '1') ){
                    carry = 0;
                    ans += '1';
                }else{
                    carry = '0';
                    ans += '0';
                }

            }

            i++;
            j++;
        }

        cout<<"yha tk string:"<<ans<<endl;

        while(j < m){
            if(carry == 1){
                if(b[j] == '0'){
                    ans += '1';
                    carry = 0;
                }else{
                    ans += '0';
                }
            }else{
                if(b[j] == '0'){
                    ans += '0';
                }else{
                    ans += '1';
                }
            }
            j++;
        }

        if(carry == 1){
            ans += '1';
        }

        reverse(ans.begin(),ans.end());
        return ans;


        
    }
};