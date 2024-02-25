class Solution {
public:

    vector<string> brute(string digits){

        if(digits.empty()){
            return {};
        }

        
        const vector<string> pad = {
            "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
        };

        vector<string> ans;
        ans.push_back("");
        for(auto digit: digits){

            vector<string> temp;

            for(auto c: pad[digit-'0']){
                for(auto a: ans){
                    temp.push_back(a+c);
                }

            }

            ans.swap(temp);

        }

        return ans;
        

       


    }
    vector<string> letterCombinations(string digits) {

        return brute(digits);

        
    }
};