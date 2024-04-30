class Solution {
public:
    void dfs(int node, vector<vector<int>>& rooms, vector<int>& vis) {
        vis[node] = 1;

        for (auto it : rooms[node]) {
            if (vis[it] == -1) {
                dfs(it, rooms, vis);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        // queue<int> q;
        // q.push(0);
        // int n = rooms.size();

        // vector<int> vis(n, -1);
        // vis[0] = 1;

        // while (!q.empty()) {
        //     auto node = q.front();
        //     q.pop();

        //     for (auto it : rooms[node]) {
        //         if (vis[it] == -1) {
        //             vis[it] = 1;
        //             q.push(it);
        //         }
        //     }
        // }

        // for (int i = 0; i < n; i++) {
        //     if (vis[i] == -1) {
        //         return false;
        //     }
        // }

        // return true;

        int n = rooms.size();
        vector<int> vis(n, -1);

        dfs(0, rooms, vis);

        for (int i = 0; i < n; i++) {
            if (vis[i] == -1) {
                return false;
            }
        }

        return true;
    }
};