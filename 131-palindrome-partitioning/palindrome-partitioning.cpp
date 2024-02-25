class Solution {
public:

    bool isPalindrome(int low, int high,string s){

        while(low <= high){
            if(s[low]!=s[high]){
                return false;
            }
            low++;
            high--;
        }

        return true;

    }

    void brute(int index,vector<string> &curr, string s, vector<vector<string>> &ans){

        if(index == s.length()){
            ans.push_back(curr);
            return;
        }


        for(int i=index; i<s.size(); ++i){

            // string str = s.substr(index,i-index+1);
            // cout<<"str:"<<str<<" ,";
            if(isPalindrome(index,i,s)){
                curr.push_back(s.substr(index,i-index+1));
                brute(i+1,curr,s,ans);
                curr.pop_back();
            }
        }

        
       
      

        
    }
    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;
        vector<string> curr;
        // generate every substring.
        brute(0,curr,s,ans);

        return ans;
        
    }
};