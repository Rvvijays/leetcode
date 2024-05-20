class Solution {
public:
    
    string brute(string s) {
        int n = s.size();
        
        for(int i = n; i > 0; i--){
            for(int j = 0; j <= n - i; j++){
                if(check(s, j, j + i)){
                    return s.substr(j, i);
                }
            }
        }
        
        return "";
    }
    
    bool check(string s, int start, int end) {
        int i = start;
        int j = end-1;
        
        while (i <= j) {
            if (s[i] != s[j]) {
                return false;
            }

            i++;
            j--;
        }
        
        return true;
    }

    string expand_str(string s, int left, int right) {

        // cout<<"checking : "<<s.substr(left, right-left+1)<<endl;

        // cout<<"before left:"<<left<<" right:"<<right<<endl;
        int start = left;
        int end = left;
        while(left >= 0 && left <= right && right <= s.length()-1){
            if(s[left] != s[right]){
                break;
                
            }

            start = left;
            end = right;
            left--;
            right++;
        }

        // cout<<"after left:"<<start<<" right:"<<end<<endl;

        // cout<<"return ing :"<<s.substr(start, end-start+1)<<endl;

        string str = s.substr(start, end-start+1);

        return str;


    }

    // b a b a d
    // 0 1 2 3 4
    // |
    
   
    string longestPalindrome(string s) {

        int n = s.size();

        if (n == 1) {
            return s;
        }

        int maxLen = 0;
        string palin = "";
        for (int i = 0; i < n; i++) {
            // cout<<"index: "<<i<<endl;
            string even = expand_str(s,i,i+1);
            string odd = expand_str(s, i,i);

            // cout<<"even:"<<even<<endl;
            // cout<<"odd:"<<odd<<endl;

            // cout<<"maxLen:"<<maxLen<<endl;

            if (maxLen <= even.size()) {
                palin = even;

                maxLen = even.size();
            }



            if (maxLen <= odd.size()) {
                palin = odd;
                maxLen = odd.size();
            }
        }

        return palin;

        
    }
};