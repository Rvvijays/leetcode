class Solution {
public:
    
    int brute(string s){
         int n = s.length();
        
        int maxLength = 0;
        
        for(int i=0; i<n; i++){
            set<char> st;
            for(int j=i; j<n; j++){
                st.insert(s[j]);
                
                if(st.size()>2){
                    break;
                }
                
                maxLength = max(maxLength, j-i+1);
            }
        }
        
        return maxLength;
    }
    
    int lengthOfLongestSubstringTwoDistinct(string s) {
       int n = s.length();
        
        int left = 0;
        int right = 0;
        int maxLength = 0;
        char hash[256] = {0};
        int cnt = 0;
        while(right < n){
            

            if(hash[s[right]]==0){
                cnt++;
            }
            
            hash[s[right]]++;
 
            
            while(cnt > 2 && left <= right){
              
                
                hash[s[left]]--;
                if(hash[s[left]]==0){
                    cnt--;
                }
                left++;
            }
            
            maxLength = max(maxLength, right - left+1);
                

            right++;
           
            
        }
        
        return maxLength;
    }
};
