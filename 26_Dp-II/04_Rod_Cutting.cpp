// recursion
class Solution {
public:

    int solve(int ind, int len, vector<int>& price) {

        if(ind == 0) {
            return len * price[0];
        }

        int notTake = solve(ind - 1, len, price);

        int take = INT_MIN;
        int rodLength = ind + 1;

        if(rodLength <= len) {
            take = price[ind] +
                   solve(ind, len - rodLength, price);
        }

        return max(take, notTake);
    }

    int rodCutting(vector<int> price, int n) {

        return solve(n - 1, n, price);
    }
};
// TC = Exponential
// SC = O(n)

// memo
class Solution {
public:

    int solve(int ind,int len,vector<int>& price,vector<vector<int>>& dp) {

        if(ind == 0) {
            return len * price[0];
        }

        if(dp[ind][len] != -1) {
            return dp[ind][len];
        }

        int notTake = solve(ind - 1,len,price,dp);

        int take = INT_MIN;
        int rodLength = ind + 1;

        if(rodLength <= len) {

            take = price[ind] +solve(ind,len - rodLength,price,dp);
        }

        return dp[ind][len] =
               max(take, notTake);
    }

    int rodCutting(vector<int> price, int n) {

        vector<vector<int>> dp(n,vector<int>(n + 1, -1));

        return solve(n - 1,n,price,dp);
    }
};
// TC = O(n²)
// SC = O(n²) + O(n)

// tab
class Solution {
public:

    int rodCutting(vector<int> price, int n) {

        vector<vector<int>> dp(
            n,
            vector<int>(n + 1, 0)
        );

        for(int len = 0; len <= n; len++) {
            dp[0][len] = len * price[0];
        }

        for(int ind = 1; ind < n; ind++) {

            int rodLength = ind + 1;

            for(int len = 0; len <= n; len++) {

                int notTake =
                    dp[ind - 1][len];

                int take = INT_MIN;

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

        return dp[n - 1][n];
    }
};
// TC = O(n²)
// SC = O(n²)
