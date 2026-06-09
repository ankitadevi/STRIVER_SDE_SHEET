// recursion
class Solution {
public:

    int solve(int ind, int len, vector<int>& price) {

        int n = price.size();

        if(ind == n)
            return 0;

        int notTake = solve(ind + 1, len, price);

        int take = 0;

        int rodLength = ind + 1;

        if(rodLength <= len) {

            take = price[ind] +
                   solve(ind,
                         len - rodLength,
                         price);
        }

        return max(take, notTake);
    }

    int rodCutting(vector<int> price, int n) {

        return solve(0, n, price);
    }
};
// TC = Exponential
// SC = O(n)

// memo
class Solution {
public:

    int solve(int ind,
              int len,
              vector<int>& price,
              vector<vector<int>>& dp) {

        int n = price.size();

        if(ind == n)
            return 0;

        if(dp[ind][len] != -1)
            return dp[ind][len];

        int notTake =
            solve(ind + 1, len, price, dp);

        int take = 0;

        int rodLength = ind + 1;

        if(rodLength <= len) {

            take = price[ind] +
                   solve(ind,
                         len - rodLength,
                         price,
                         dp);
        }

        return dp[ind][len] =
               max(take, notTake);
    }

    int rodCutting(vector<int> price, int n) {

        vector<vector<int>> dp(
            n,
            vector<int>(n + 1, -1)
        );

        return solve(0, n, price, dp);
    }
};
// TC = O(n²)
// SC = O(n²) + O(n)

// tab
class Solution {
public:

    int rodCutting(vector<int> price, int n) {

        vector<vector<int>> dp(
            n + 1,
            vector<int>(n + 1, 0)
        );

        for(int ind = n - 1;
            ind >= 0;
            ind--) {

            int rodLength = ind + 1;

            for(int len = 0;
                len <= n;
                len++) {

                int notTake =
                    dp[ind + 1][len];

                int take = 0;

                if(rodLength <= len) {

                    take =
                        price[ind]
                        + dp[ind]
                            [len - rodLength];
                }

                dp[ind][len] =
                    max(take, notTake);
            }
        }

        return dp[0][n];
    }
};
// TC = O(n²)
// SC = O(n²)
