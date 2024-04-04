class DisjointSet {
    vector<int> parent, rank;

    public:
    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1);

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

    void unionByRank(int u, int v){
        int pv = findParent(v);

        int pu = findParent(u);

        if(pu == pv){
            return;
        }

        if(rank[pu]<rank[pv]){
            parent[pu] = pv;
        }else if(rank[pv]<rank[pu]){
            parent[pv] = pu;
        }else{
            parent[pv] = pu;
            rank[pu]++;
        }
    }


};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {

        int n = stones.size();


        int row =0;
        int col = 0;

       for(auto it : stones) {

        if(row < it[0]){
            row = it[0];
        }

        if(col < it[1]){
            col = it[1];
        }

       }

    //    cout<<"row:"<<row<<" col:"<<col<<endl;
    int nodes = row + col + 2;

        DisjointSet ds(nodes);


        for(auto it : stones){

            // cout<<"row:"<<it[0]<<" col:"<<it[1]<<endl;
            // cout<<"u:"<<it[0]<<" v:"<<it[1]+it[0]+1<<endl;
            int u = it[0];
            int v = it[1] + row + 1;
            // cout<<"connecting u:"<<u<<" v:"<<v<<endl;
            ds.unionByRank(u,v);
        }

        vector<int> connected(nodes,0);
        for(int i=0; i<nodes; i++){
            // cout<<"node:"<<i<<" parent:"<<ds.findParent(i)<<endl;
            if(ds.findParent(i)==i){
                continue;
            }

            connected[ds.findParent(i)]++;
        }
        int com =0;
        for(int i=0; i<nodes; i++){
            if(connected[i]>0){
                com++;
            }
        }

        return n-com;



    }
};