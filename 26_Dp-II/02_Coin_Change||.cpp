// recursion
class Solution {
public:
    int solve(int idx, int amount, vector<int>& coins) {

        if(idx == 0) {
            return (amount % coins[0] == 0);
        }

        int notTake = solve(idx - 1, amount, coins);

        int take = 0;
        if(coins[idx] <= amount)
            take = solve(idx, amount - coins[idx], coins);

        return take + notTake;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        return solve(n - 1, amount, coins);
    }
};

// memo
class Solution {
public:
    int solve(int idx, int amount,
              vector<int>& coins,
              vector<vector<int>>& dp) {

        if(idx == 0) {
            return (amount % coins[0] == 0);
        }

        if(dp[idx][amount] != -1)
            return dp[idx][amount];

        int notTake = solve(idx - 1, amount, coins, dp);

        int take = 0;
        if(coins[idx] <= amount)
            take = solve(idx, amount - coins[idx], coins, dp);

        return dp[idx][amount] = take + notTake;
    }

    int change(int amount, vector<int>& coins) {

        int n = coins.size();

        vector<vector<int>> dp(n,
                               vector<int>(amount + 1, -1));

        return solve(n - 1, amount, coins, dp);
    }
};

// tab
class Solution {
public:
    int change(int amount, vector<int>& coins) {

        int n = coins.size();

        vector<vector<int>> dp(n,
                               vector<int>(amount + 1, 0));

        for(int amt = 0; amt <= amount; amt++) {
            if(amt % coins[0] == 0)
                dp[0][amt] = 1;
        }

        for(int idx = 1; idx < n; idx++) {

            for(int amt = 0; amt <= amount; amt++) {

                int notTake = dp[idx - 1][amt];

                int take = 0;
                if(coins[idx] <= amt)
                    take = dp[idx][amt - coins[idx]];

                dp[idx][amt] = take + notTake;
            }
        }

        return dp[n - 1][amount];
    }
};

// | Approach        | Time Complexity | Space Complexity |
// | --------------- | --------------- | ---------------- |
// | Recursion       | Exponential     | O(A+n)           |
// | Memoization     | O(n×A)          | O(n×A) + O(A+n)  |
// | Tabulation      | O(n×A)          | O(n×A)           |
