class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    bool isReachable(vector<vector<char>>& grid, int x, int y, int i, int j) {

        if (x == i && y == j) {
            return true;
        }

        int n = grid.size();
        int m = grid[0].size();
        // char temp = grid[x][y];
        // grid[x][y] = '#';

        bool visited[n][m];
        memset(visited,false,sizeof(visited));
        queue<vector<int>> q;
        q.push({x,y});

        while(!q.empty()) {

            vector<int> points = q.front();
            q.pop();

            if(points[0] == i && points[1] == j){
                return true;
            }

            for(int k=0; k<4; k++) {
                int nx = points[0] + dx[k];
                int ny = points[1] + dy[k];

                if(nx < 0 || ny < 0 || nx >= n || ny >= m ||
                visited[nx][ny]==true || grid[nx][ny] == '#') {
                    continue;
                }

                visited[nx][ny] = true;
                q.push({nx,ny});
            }
        }

        // for (int k = 0; k < 4; k++) {
        //     int nx = x + dx[k];
        //     int ny = y + dy[k];

        //     if (nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny] == '#') {
        //         continue;
        //     }

        //     if (isReachable(grid, nx, ny, i, j)) {
        //         // cout<<"reachable:"<<endl;
        //         grid[x][y] = temp;

        //         return true;
        //     }
        // }

        // grid[x][y] = temp;

        return false;
    }
    int minPushBox(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int sx, sy, bx, by, tx, ty;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'B') {
                    bx = i;
                    by = j;
                }

                if (grid[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }

                if (grid[i][j] == 'T') {
                    tx = i;
                    ty = j;
                }
            }
        }

        queue<vector<int>> q;
        q.push({bx, by, sx, sy});

        int level = 0;

        bool visited[n][m][n][m];
        memset(visited, false, sizeof(visited));

        visited[bx][by][sx][sy] = true;
        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                vector<int> points = q.front();
                q.pop();

                // cout<<"yee..."<<endl;

                bx = points[0];
                by = points[1];
                sx = points[2];
                sy = points[3];

                if (bx == tx && by == ty) {
                    return level;
                }
                grid[bx][by] = '#';
                for (int k = 0; k < 4; k++) {
                    int nbx = bx + dx[k];
                    int nby = by + dy[k];
                    int nsx = bx - dx[k];
                    int nsy = by - dy[k];

                    if (nbx < 0 || nbx >= n || nby < 0 || nby >= m || nsx < 0 ||
                        nsx >= n || nsy < 0 || nsy >= m) {
                        continue;
                    }

                    if (visited[nbx][nby][nsx][nsy] || grid[nbx][nby] == '#' ||
                        grid[nsx][nsy] == '#') {
                        continue;
                    }

                    if (isReachable(grid, sx, sy, nsx, nsy)) {
                        visited[nbx][nby][nsx][nsy] = true;
                        q.push({nbx, nby, nsx, nsy});
                    }
                }

                grid[bx][by] = '.';
            }
            level++;
        }

        return -1;
    }
};