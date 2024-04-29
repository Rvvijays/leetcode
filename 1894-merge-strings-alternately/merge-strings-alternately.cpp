class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int p1 = 0;
		int p2 = 0;
		
		int n = word1.length();
		int m = word2.length();
		string ans = "";
		
		while(p1 < n && p2 < m){
				ans += word1[p1];
				ans += word2[p2];
				
				p1++;
				p2++;
		}
		
		while(p1<n){
				ans += word1[p1];
				p1++;
		}
		
		while(p2<m){
				ans += word2[p2];
				p2++;
		}
		
		return ans;
    }
};