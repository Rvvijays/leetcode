class DS{
    vector<int> parent,size;
    public:
    DS(int n){
        parent.resize(n+1);
        size.resize(n+1,0);

        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
    }

    int findParent(int node){
        if(node == parent[node]){
            return node;
        }

        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u,int v){
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu == pv){
            return;
        }

        if(size[pu]<size[pv]){
            parent[pu] = pv;
            size[pv]++;
        }else{
            parent[pv] = pu;
            size[pu]++;
        }
    }

};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        DS ds(accounts.size());
        map<string,int> mp;

        for(int i=0; i<accounts.size(); i++){

           for(int j=1; j<accounts[i].size(); j++){

            if(mp.find(accounts[i][j])!=mp.end()){
                ds.unionBySize(i,mp[accounts[i][j]]);
            }else{
                mp[accounts[i][j]] = i;
            }

            
           }
        }


        vector<vector<string>> mergedMails(accounts.size());

        for(auto it : mp) {
            string mail = it.first;
            int node = ds.findParent(it.second);
            // cout<<"parent:"<<node<<endl;
            mergedMails[node].push_back(mail);

        }

        vector<vector<string>> ans;

        for(int i=0; i<mergedMails.size(); i++) {
            if(mergedMails[i].size()==0){
                continue;
            }
            sort(mergedMails[i].begin(),mergedMails[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto jj : mergedMails[i]){
                temp.push_back(jj);
            }
            ans.push_back(temp);
        }

       return ans;
    }
};