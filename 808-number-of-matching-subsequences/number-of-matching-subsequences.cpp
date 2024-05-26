

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {

       
        // vector<pair<int,int>> q[26];

        // for(int i=0; i<words.size(); i++) {
        //     q[words[i][0] - 'a'].push_back({i,1});
        // }

        // int matches = 0;

        // for(int i = 0; i<s.size(); i++) {
        //     int ch = s[i] - 'a';

        //     if(q[ch].size() == 0){
        //         continue;
        //     }


        //     vector<pair<int,int>> curr = q[ch];
        //     q[ch].clear();

        //     for(auto& [key,i] : curr) {
        //         if(i == words[key].size()) {
        //             matches++;
        //         }else{
        //             q[words[key][i] - 'a'].push_back({key,i+1});
        //         }


        //     }
        // }

        // return matches;

        unordered_map<char,vector<int>> mp;
        for(int i = 0; i < s.length(); i++) {
            mp[s[i]].push_back(i);
        }

        int ans = 0;


        for(int j=0; j<words.size(); j++) {
            int prev = -1;
            string word = words[j];
            int i = 0;

            bool found = true;
            while(i < word.length()) {
                auto nextIndex = upper_bound( mp[word[i]].begin(),  mp[word[i]].end(), prev);
                if(nextIndex ==  mp[word[i]].end()) {
                    found = false;
                    break;
                }
                prev = *nextIndex;
                i++;
            }

            if(found) {
                ans++;
            }

        }

        return ans;


    }
};