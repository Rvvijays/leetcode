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

    void generate(string prefix,int index,string digits,vector<string> &keys,vector<string> &ans){

        if(index >= digits.length()){
            ans.push_back(prefix);
            return;
        }


        string letters = keys[digits[index] - '0'];
        // cout<<"letters:"<<letters;

        for(auto letter : letters) {
            generate(prefix+letter,index+1,digits,keys,ans);
        }

    }


    vector<string> letterCombinations(string digits) {

        // return brute(digits);

        if(digits.length()==0){
            return {};
        }

        vector<string> ans;

        vector<string> keys = {
            "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
        };
        generate("",0,digits,keys,ans);
        return ans;

        
    }
};