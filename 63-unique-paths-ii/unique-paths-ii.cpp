class Solution {
public:
    int recursion(int i, int j, vector<vector<int>>& grid) {
        if (i == 0 && j == 0) {
            return 1;
        }

        if (i < 0 || j < 0) {
            return 0;
        }

        if (grid[i][j] == 1) {
            return 0;
        }

        int left = recursion(i - 1, j, grid);
        int top = recursion(i, j - 1, grid);
        return left + top;
    }

    int memorization(int i, int j, vector<vector<int>>& grid,
                     vector<vector<int>>& dp) {
        if (i == 0 && j == 0) {
            return 1;
        }

        if (i < 0 || j < 0) {
            return 0;
        }

        if (grid[i][j] == 1) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int left = memorization(i - 1, j, grid, dp);
        int top = memorization(i, j - 1, grid, dp);
        return dp[i][j] = left + top;
    }

    int tabulation(int n, int m, vector<vector<int>>& grid) {

        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // if (grid[i][j] == 0) {
                if (i == 0 && j == 0) {
                    dp[i][j] = 1;
                } else {

                    if (i > 0 && grid[i - 1][j] == 0) {
                        dp[i][j] += dp[i - 1][j];
                    }

                    if (j > 0 && grid[i][j - 1] == 0) {
                        dp[i][j] += dp[i][j - 1];
                    }
                }
                // }
            }
        }

        return dp[n - 1][m - 1];
    }

    int spaceoptimization(int n, int m, vector<vector<int>>& grid) {

        // vector<vector<int>> dp(n, vector<int>(m, 0));

        vector<int> prev(m,0);

        for (int i = 0; i < n; i++) {

            vector<int> cur(m,0);
            for (int j = 0; j < m; j++) {

                // if (grid[i][j] == 0) {
                if (i == 0 && j == 0) {
                    // dp[i][j] = 1;
                    cur[0] = 1;
                } else {

                    if (i > 0 && grid[i - 1][j] == 0) {
                        cur[j] += prev[j];
                    }

                    if (j > 0 && grid[i][j - 1] == 0) {
                        cur[j] += cur[j - 1];
                    }
                }
                // }
            }
            prev = cur;
        }

        return prev[m - 1];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1) {
            return 0;
        }

        // return recursion(n-1,m-1,grid);
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        // return memorization(n-1,m-1,grid,dp);

        // return tabulation(n, m, grid);
        return spaceoptimization(n, m, grid);
    }
};