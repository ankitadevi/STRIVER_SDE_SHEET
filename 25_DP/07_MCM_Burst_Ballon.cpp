// recurrsion
class Solution {
public:

    int solve(int i, int j, vector<int>& nums){

        if(i == j) return 0;

        int mini = INT_MAX;

        for(int k = i; k < j; k++){

            int cost =
                solve(i, k, nums)
                + solve(k + 1, j, nums)
                + nums[i - 1] * nums[k] * nums[j];

            mini = min(mini, cost);
        }

        return mini;
    }

    int matrixMultiplication(vector<int>& nums){

        int n = nums.size();

        return solve(1, n - 1, nums);
    }
// };
// Time  : Exponential
// Space : O(n) recursion stack

// memo
class Solution {
public:

    int solve(int i, int j,
              vector<int>& nums,
              vector<vector<int>>& dp){

        if(i == j) return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int mini = INT_MAX;

        for(int k = i; k < j; k++){

            int cost =
                solve(i, k, nums, dp)
                + solve(k + 1, j, nums, dp)
                + nums[i - 1] * nums[k] * nums[j];

            mini = min(mini, cost);
        }

        return dp[i][j] = mini;
    }

    int matrixMultiplication(vector<int>& nums){

        int n = nums.size();

        vector<vector<int>> dp(n,
                               vector<int>(n, -1));

        return solve(1, n - 1, nums, dp);
    }
};
// Time  = O(n³)
// Space = O(n²) + O(n)

// tab
class Solution {
public:

    int matrixMultiplication(vector<int>& nums){

        int n = nums.size();

        vector<vector<int>> dp(n,
                               vector<int>(n, 0));

        for(int i = n - 1; i >= 1; i--){

            for(int j = i + 1; j < n; j++){

                int mini = INT_MAX;

                for(int k = i; k < j; k++){

                    int cost =
                        dp[i][k]
                        + dp[k + 1][j]
                        + nums[i - 1] * nums[k] * nums[j];

                    mini = min(mini, cost);
                }

                dp[i][j] = mini;
            }
        }

        return dp[1][n - 1];
    }
};
// Time  = O(n³)
// Space = O(n²) 
