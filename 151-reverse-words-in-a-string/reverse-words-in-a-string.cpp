class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int left = 0;
        int right = 0;
        int n = s.size();

        int index = 0;
        
        while(index<n){
            
            while(index<n && isspace(s[index])){
                index++;
            }

            if(index == n){
                break;
            }
            
           
            
            while(index<n && !isspace(s[index])){
                s[right] = s[index];
                index++;
                right++;
            }


            reverse(s.begin()+left, s.begin()+right);

            s[right] = ' ';
            right++;
            left = right;
            index++;
        }

        s.resize(right-1);
        
        return s;
    }
};