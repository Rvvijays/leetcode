class Solution {
public:
    bool isSubsequence(string s, string t) {

        int n = s.size();
        int m = t.size();

        int left = 0;
        int right = 0;

        while (left < n && right < m) {
            if (s[left] == t[right]) {
                left++;
                right++;
            } else {
                right++;
            }
        }

        if (left == n) {
            return true;
        }

        return false;
    }
};