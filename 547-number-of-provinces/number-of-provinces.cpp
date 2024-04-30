class Disjoint {
    vector<int> rank;
    vector<int> parent;
    vector<int> size;

public:
    Disjoint(int n) {
        rank.resize(n);
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int node) {
        if (parent[node] == node) {
            return node;
        }

        return parent[node] = find(parent[node]);
    }

    void print() {
        for (int i = 0; i < rank.size(); i++) {
            cout << i << " :" << parent[i] << endl;
        }
    }

    void unionByRank(int u, int v) {

        int pu = find(u);
        int pv = find(v);

        if (pu == pv) {
            return;
        }

        if (rank[pu] < rank[pv]) {
            parent[pv] = pu;
        } else if (rank[pv] < rank[pu]) {
            parent[pu] = pv;
        } else {
            parent[pu] = pv;
            rank[pu]++;
        }
    }
};

class Solution {
public:
    void dfs(int node, vector<vector<int>>& list, vector<int>& vis) {
        vis[node] = 1;

        for (int i = 0; i < list[node].size(); i++) {
            if (list[node][i] == 1 && vis[i] != 1) {
                dfs(i, list, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();

        Disjoint ds(n);


        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j] == 1){
            ds.unionByRank(i, j);

                }
            }
        }

        // for (auto it : isConnected) {

        //     int u = it[0];
        //     int v = it[1];
        // }
        // cout << "parents:" << endl;
        // ds.print();

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (ds.find(i) == i) {
                count++;
            }
        }

        return count;

        // vector<int> vis(n,0);

        // int count = 0;

        // for(int i=0; i<n; i++){
        //     if(vis[i]!=1){
        //         dfs(i,isConnected,vis);
        //         count++;
        //     }
        // }

        // return count;
    }
};