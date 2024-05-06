class Solution {
public:
    
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0){
            return 0;
        }
        unordered_map<char,bool> hash;
        int maxi = 1;
        
        for(int i=0; i<n; i++){
            hash.clear();
            hash[s[i]] = true;
            int count = 1;
           for(int j=i+1; j<n; j++){
               if(hash[s[j]]){
                   break;
               }else{
                   count++;
                   hash[s[j]] = true;
               }
           }
                maxi = max(maxi,count);
            
            
        }
        
        // maxi = max(maxi,count);
        
        return maxi;
        
    }
};