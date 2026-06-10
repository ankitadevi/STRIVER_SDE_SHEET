// recursion
class Solution {
public:
    bool solve(int idx, int target, vector<int>& arr) {

        // Target achieved
        if(target == 0) return true;

        // Reached end of array
        if(idx == arr.size()) return false;

        bool notTake = solve(idx + 1, target, arr);

        bool take = false;
        if(arr[idx] <= target)
            take = solve(idx + 1, target - arr[idx], arr);

        return take || notTake;
    }

    bool isSubsetSum(vector<int> arr, int target) {
        return solve(0, target, arr);
    }
};
// memo
class Solution {
public:
    bool solve(int idx, int target,
               vector<int>& arr,
               vector<vector<int>>& dp) {

        if(target == 0) return true;

        if(idx == arr.size()) return false;

        if(dp[idx][target] != -1)
            return dp[idx][target];

        bool notTake = solve(idx + 1, target, arr, dp);

        bool take = false;
        if(arr[idx] <= target)
            take = solve(idx + 1, target - arr[idx], arr, dp);

        return dp[idx][target] = take || notTake;
    }

    bool isSubsetSum(vector<int> arr, int target) {

        int n = arr.size();

        vector<vector<int>> dp(
            n, vector<int>(target + 1, -1));

        return solve(0, target, arr, dp);
    }
};
// tab
class Solution {
public:
    bool isSubsetSum(vector<int> arr, int target) {

        int n = arr.size();

        vector<vector<bool>> dp(
            n, vector<bool>(target + 1, false));

        for(int i = 0; i < n; i++)
            dp[i][0] = true;

        if(arr[0] <= target)
            dp[0][arr[0]] = true;

        for(int i = 1; i < n; i++) {

            for(int t = 1; t <= target; t++) {

                bool notTake = dp[i - 1][t];

                bool take = false;

                if(arr[i] <= t)
                    take = dp[i - 1][t - arr[i]];

                dp[i][t] = take || notTake;
            }
        }

        return dp[n - 1][target];
    }
};

// | Approach        | Time Complexity      | Space Complexity            |
// | --------------- | -------------------- | --------------------------- |
// | Recursion       | (O(2^n))             | (O(n))                      |
// | Memoization     | (O(n*target))        | (O(n*target) + O(n))        |
// | Tabulation      | (O(n*target))        | (O(n*target))               |
// | Space Optimized | (O(n*target))        | (O(target))                 |

