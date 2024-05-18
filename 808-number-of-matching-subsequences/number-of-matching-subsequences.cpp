

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {

       
        vector<pair<int,int>> q[26];

        for(int i=0; i<words.size(); i++) {
            q[words[i][0] - 'a'].push_back({i,1});
        }

        int matches = 0;

        for(int i = 0; i<s.size(); i++) {
            int ch = s[i] - 'a';

            if(q[ch].size() == 0){
                continue;
            }


            vector<pair<int,int>> curr = q[ch];
            q[ch].clear();

            for(auto& [key,i] : curr) {
                if(i == words[key].size()) {
                    matches++;
                }else{
                    q[words[key][i] - 'a'].push_back({key,i+1});
                }


            }
        }

        return matches;


    }
};