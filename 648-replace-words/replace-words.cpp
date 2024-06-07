class Solution {
public:
    string brute(vector<string>& dictionary, string sentence) {
        unordered_map<string, bool> hash;

        for (int i = 0; i < dictionary.size(); i++) {
            hash[dictionary[i]] = true;
        }

        // sc: o(n)
        // tc: o(nlogn)

        string ans;

        stringstream s(sentence);
        string temp;

        while (getline(s, temp, ' ')) {
            string tt = "";
            bool found = false;
            for (int i = 0; i < temp.size(); i++) {
                tt += temp[i];

                if (hash.find(tt) != hash.end()) {
                    ans += tt + " ";
                    found = true;
                    break;
                }
            }

            if (!found) {
                ans += tt + " ";
            }
        }

        // tc : o(nm)

        ans.pop_back();

        return ans;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {

        return brute(dictionary, sentence);



    }
};