class Solution {
public:

    bool dfs(string &ans, int total, int k, int n, unordered_set<string> &vis){
        if(vis.size() == total){
            return true;
        }

        string s = ans.substr(ans.length()-n+1,n-1);

        for(int i=0; i<k; i++){
            string temp = s + to_string(i);
            ans += to_string(i);
            if(vis.find(temp) == vis.end()){
                vis.insert(temp);
                if(dfs(ans,total,k,n,vis)){
                    return true;
                }
                vis.erase(temp);
            }

            ans.pop_back();

        }

        return false;
    }
    string crackSafe(int n, int k) {

        string ans = "";
        unordered_set<string> vis;

        for(int i=0; i<n; i++){
            ans += "0";
        }

        vis.insert(ans);
        int total = pow(k,n);

        dfs(ans,total,k,n,vis);


        return ans;







        
    }
};