// Recurrsion
class Solution {
public:

    int solve(int i, int prev, vector<int>& arr, int n) {

        if(i == n) return 0;

        int notTake = solve(i + 1, prev, arr, n);

        int take = 0;

        if(prev == -1 || arr[i] > arr[prev]) {
            take = arr[i] + solve(i + 1, i, arr, n);
        }

        return max(take, notTake);
    }

    int maxSumIncreasingSubsequence(vector<int>& arr, int n) {

        return solve(0, -1, arr, n);
    }
};
// TC = O(2^n)
// SC = O(n)

// memo
class Solution {
public:

    int solve(int i,
              int prev,
              vector<int>& arr,
              int n,
              vector<vector<int>>& dp) {

        if(i == n) return 0;

        if(dp[i][prev + 1] != -1)
            return dp[i][prev + 1];

        int notTake = solve(i + 1, prev, arr, n, dp);

        int take = 0;

        if(prev == -1 || arr[i] > arr[prev]) {
            take = arr[i] +
                   solve(i + 1, i, arr, n, dp);
        }

        return dp[i][prev + 1] =
               max(take, notTake);
    }

    int maxSumIncreasingSubsequence(vector<int>& arr, int n) {

        vector<vector<int>> dp(
            n,
            vector<int>(n + 1, -1)
        );

        return solve(0, -1, arr, n, dp);
    }
};
// TC = O(n²)
// SC = O(n²) + O(n)

// Tab
class Solution {
public:

    int maxSumIncreasingSubsequence(vector<int>& arr, int n) {

        vector<int> dp(n);

        for(int i = 0; i < n; i++) {
            dp[i] = arr[i];
        }

        int ans = arr[0];

        for(int i = 0; i < n; i++) {

            for(int prev = 0; prev < i; prev++) {

                if(arr[prev] < arr[i]) {

                    dp[i] = max(
                        dp[i],
                        arr[i] + dp[prev]
                    );
                }
            }

            ans = max(ans, dp[i]);
        }

        return ans;
    }
};
// TC = O(n²)
// SC = O(n)
