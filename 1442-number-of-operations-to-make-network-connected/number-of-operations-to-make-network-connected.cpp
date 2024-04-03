class DisjointSet{
    vector<int> parent,size,rank;

    public:
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        rank.resize(n+1,0);

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
        int pv = findParent(v);
        int pu = findParent(u);

        if(pv == pu){
            return;
        }

        if(size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv]++;
        }else{
            parent[pv] = pu;
            size[pu]++;
        }
    }

    void unionByRank(int u, int v){
        int pv = findParent(v);
        int pu = findParent(u);

        if(pv == pu){
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
    int makeConnected(int n, vector<vector<int>>& connections) {

        int totalEdges = connections.size();

        DisjointSet ds(n);

        int minimumEdges = 0;

        for(int i=0; i<totalEdges; i++){
            int u = connections[i][0];
            int v = connections[i][1];

            if(ds.findParent(u)!=ds.findParent(v)){
                minimumEdges++;
                ds.unionByRank(u,v);
            }
        }


        int extraEdges = totalEdges - minimumEdges;

        int components = 0;
        for(int i=0; i<n; i++){
            if(ds.findParent(i) == i){
                components++;
            }
        }

        // cout<<"extra:"<<extraEdges<<endl;
        // cout<<"componetns:"<<components<<endl;

        if(extraEdges >= components-1){
            return components-1;
        }

       
       return -1;

      

    }
};