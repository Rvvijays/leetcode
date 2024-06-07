class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        map<string,bool> hash;

        for(int i=0; i<dictionary.size(); i++) {
            hash[dictionary[i]] = true;
        }

        string ans;
        
        stringstream s(sentence);
        string temp;

        while(getline(s,temp,' ')) {
            string tt = "";
            bool found = false;
            for(int i=0; i<temp.size(); i++) {
                tt += temp[i];

                if(hash.find(tt)!= hash.end()) {
                    ans += tt + " ";
                    found = true;
                    break;
                }
            }

            if(!found){
            ans += tt + " ";

            }
        }

        ans.pop_back();

        return ans;
    }
};