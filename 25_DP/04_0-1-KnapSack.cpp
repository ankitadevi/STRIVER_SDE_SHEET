// recursion

class Solution{
public:

    int solve(int idx, int W,
              vector<int>& wt,
              vector<int>& val){

        if(idx == wt.size()) return 0;

        int notTake = solve(idx + 1, W, wt, val);

        int take = 0;
        if(wt[idx] <= W)
            take = val[idx] +
                   solve(idx + 1,
                         W - wt[idx],
                         wt, val);

        return max(take, notTake);
    }

    int knapsack01(vector<int>& wt,
                   vector<int>& val,
                   int n, int W) {

        return solve(0, W, wt, val);
    }
};

// memo

class Solution{
public:

    int solve(int idx, int W,
              vector<int>& wt,
              vector<int>& val,
              vector<vector<int>>& dp){

        if(idx == wt.size()) return 0;

        if(dp[idx][W] != -1)
            return dp[idx][W];

        int notTake =
            solve(idx + 1, W, wt, val, dp);

        int take = 0;
        if(wt[idx] <= W)
            take = val[idx] +
                   solve(idx + 1,
                         W - wt[idx],
                         wt, val, dp);

        return dp[idx][W] =
               max(take, notTake);
    }

    int knapsack01(vector<int>& wt,
                   vector<int>& val,
                   int n, int W) {

        vector<vector<int>> dp(
            n, vector<int>(W + 1, -1));

        return solve(0, W, wt, val, dp);
    }
};

// tab

class Solution{
public:

    int knapsack01(vector<int>& wt,
                   vector<int>& val,
                   int n, int W) {

        vector<vector<int>> dp(
            n, vector<int>(W + 1, 0));

        for(int w = wt[0]; w <= W; w++)
            dp[0][w] = val[0];

        for(int i = 1; i < n; i++){

            for(int w = 0; w <= W; w++){

                int notTake = dp[i-1][w];

                int take = 0;

                if(wt[i] <= w)
                    take = val[i] +
                           dp[i-1][w - wt[i]];

                dp[i][w] =
                    max(take, notTake);
            }
        }

        return dp[n-1][W];
    }
};

// | Approach        | Time Complexity | Space Complexity     |
// | --------------- | --------------- | -------------------- |
// | Recursion       | (O(2^n))        | (O(n))               |
// | Memoization     | (O(n \times W)) | (O(n \times W)+O(n)) |
// | Tabulation      | (O(n \times W)) | (O(n \times W))      |
// | Space Optimized | (O(n \times W)) | (O(W))               |
