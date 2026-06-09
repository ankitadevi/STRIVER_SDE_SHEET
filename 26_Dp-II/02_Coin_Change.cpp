// recursion
class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid) {
        
        if(i == 0 && j == 0)
            return grid[0][0];

        if(i < 0 || j < 0)
            return 1e9;

        int up = grid[i][j] + solve(i - 1, j, grid);
        int left = grid[i][j] + solve(i, j - 1, grid);

        return min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        return solve(m - 1, n - 1, grid);
    }
};
// Complexity
// Time: O(2^(m+n))
// Space: O(m+n) (recursion stack)

// memo
class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid,
              vector<vector<int>>& dp) {

        if(i == 0 && j == 0)
            return grid[0][0];

        if(i < 0 || j < 0)
            return 1e9;

        if(dp[i][j] != -1)
            return dp[i][j];

        int up = grid[i][j] + solve(i - 1, j, grid, dp);
        int left = grid[i][j] + solve(i, j - 1, grid, dp);

        return dp[i][j] = min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(m - 1, n - 1, grid, dp);
    }
};
// Time: O(m*n)
// Space: O(m*n) + O(m+n)

// tab
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(i == 0 && j == 0) {
                    dp[i][j] = grid[i][j];
                    continue;
                }

                int up = 1e9;
                int left = 1e9;

                if(i > 0)
                    up = grid[i][j] + dp[i - 1][j];

                if(j > 0)
                    left = grid[i][j] + dp[i][j - 1];

                dp[i][j] = min(up, left);
            }
        }

        return dp[m - 1][n - 1];
    }
};
// Complexity
// Time: O(m*n)
// Space: O(m*n)
