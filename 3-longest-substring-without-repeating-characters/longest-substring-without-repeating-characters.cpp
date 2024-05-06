class Solution {
public:
    int brute(string s) {
        int n = s.size();
        if (n == 0) {
            return 0;
        }
        unordered_map<char, bool> hash;
        int maxi = 1;

        for (int i = 0; i < n; i++) {
            hash.clear();
            hash[s[i]] = true;
            int count = 1;
            for (int j = i + 1; j < n; j++) {
                if (hash[s[j]]) {
                    break;
                } else {
                    count++;
                    hash[s[j]] = true;
                }
            }
            maxi = max(maxi, count);
        }

        return maxi;
    }

    int lengthOfLongestSubstring(string s) {

        int n = s.length();

        int left = 0;
        int right = 0;

        unordered_map<char,int> hash;
        int maxLength = 0;

        while(right < n){

            if(hash.find(s[right]) != hash.end()){
                int prevIndex = hash[s[right]];

                if(prevIndex >= left){
                    left = prevIndex + 1;
                }

            }

            hash[s[right]] = right;


            int length = right - left + 1;

            maxLength = max(maxLength,length);

            right++;



        }

        return maxLength;
    }
};