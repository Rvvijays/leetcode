class Solution {
public:
    int firstUniqChar(string s) {

        int n = s.length();

        for(int i=0; i<n; i++){
            bool found = false;

            for(int j=0; j<n; j++){
                // cout<<"i:"<<s[i]<<" j:"<<s[j]<<endl;
                if(i!=j && s[i]==s[j]){
                    found = true;
                    break;
                }
            }

            if(found==false){
                return i;
            }
        }
        return -1;
        
    }
};