// recursion
class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        if(i == m-1 && j == n-1)
            return grid[i][j];

        if(i >= m || j >= n)
            return 1e9;

        int down = solve(i+1, j, grid);
        int right = solve(i, j+1, grid);

        return grid[i][j] + min(down, right);
    }

    int minPathSum(vector<vector<int>>& grid) {
        return solve(0, 0, grid);
    }
};
// Complexity
// Time: O(2^(m+n))
// Space: O(m+n) (recursion stack)

// memo
class Solution {
public:
    int solve(int i, int j,
              vector<vector<int>>& grid,
              vector<vector<int>>& dp) {

        int m = grid.size();
        int n = grid[0].size();

        if(i == m-1 && j == n-1)
            return grid[i][j];

        if(i >= m || j >= n)
            return 1e9;

        if(dp[i][j] != -1)
            return dp[i][j];

        int down = solve(i+1, j, grid, dp);
        int right = solve(i, j+1, grid, dp);

        return dp[i][j] = grid[i][j] + min(down, right);
        }
        // dp[i][j] = minimum cost from (i,j)
        //    to reach destination
    

    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(0, 0, grid, dp);
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

        dp[0][0] = grid[0][0];

        // First row
        for(int j = 1; j < n; j++) {
            dp[0][j] = grid[0][j] + dp[0][j - 1];
        }

        // First column
        for(int i = 1; i < m; i++) {
            dp[i][0] = grid[i][0] + dp[i - 1][0];
        }

        // Remaining cells
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[i][j] = grid[i][j] +
                           min(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[m - 1][n - 1];
    }
};
// Complexity
// Time: O(m*n)
// Space: O(m*n)
