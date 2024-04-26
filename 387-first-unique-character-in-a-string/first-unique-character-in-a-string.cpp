class Solution {
public:
    int firstUniqChar(string s) {

        int n = s.length();

        vector<int> count(26,-1);

        for(int i=0; i<n; i++){
            count[s[i] - 97]++;
        }

        for(int i=0; i<n; i++){
            if(count[s[i]- 97]==0){
                return i;
            }
        }



        // for(int i=0; i<n; i++){
        //     bool found = false;

        //     for(int j=0; j<n; j++){
        //         if(i!=j && s[i]==s[j]){
        //             found = true;
        //             break;
        //         }
        //     }
        //     if(found==false){
        //         return i;
        //     }
        // }
        return -1;
        
    }
};