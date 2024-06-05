class Solution {
public:
    vector<string> commonChars(vector<string>& words) {

        int hash[26] = {0};

        for(int i=0; i<words[0].size(); i++) {
            hash[words[0][i] - 'a']++;
        }


        for(int i = 1; i<words.size(); i++) {
            int loc[26] = {0};

            for(int j=0; j<words[i].size(); j++) {
                loc[words[i][j] - 'a']++;
            }

            for(int j=0; j<26; j++) {
                hash[j] = min(hash[j],loc[j]);
            }
        }


        vector<string> ans;
        for(int i=0; i<26; i++) {

            int count = hash[i];

            for(int j=0; j<count; j++) {
                ans.push_back({char(i+'a')});
            }

        }

        return ans;
    }
};