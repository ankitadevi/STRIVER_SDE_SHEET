// Longest Increasing Subsequence | (DP-41)
// In the coming articles, we will discuss problems related to ‘Longest Increasing Subsequence’. Before proceeding further, let us understand the “Longest Increasing Subsequence”, or rather what is a “subsequence”?
// A subsequence of an array is a list of elements of the array where some elements are deleted ( or not deleted at all) and they should be in the same order in the subsequence as in the original array.
// For example, for the array: [2,3,1] , the subsequences will be [{2},{3},{1},{2,3},{2,1},{3,1},{2,3,1}} but {3,2} is not a subsequence because its elements are not in the same order as the original array.

//Leetcode: 300 link:https://leetcode.com/problems/longest-increasing-subsequence/description/

// Brute Force (Recursion)
class Solution {
public:
    int solve(int ind, int prev, vector<int>& nums) {
        if(ind == nums.size()) return 0;

        int notTake = solve(ind + 1, prev, nums);

        int take = 0;
        if(prev == -1 || nums[ind] > nums[prev]) {
            take = 1 + solve(ind + 1, ind, nums);
        }

        return max(take, notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
        return solve(0, -1, nums);
    }
};
// Complexity
// Time: O(2ⁿ)
// Space: O(n) (recursion stack)

// DP Memoization (Top-Down)
class Solution {
public:
    int solve(int ind, int prev, vector<int>& nums,
              vector<vector<int>>& dp) {

        if(ind == nums.size()) return 0;

        if(dp[ind][prev + 1] != -1)
            return dp[ind][prev + 1]; 

        int notTake = solve(ind + 1, prev, nums, dp);

        int take = 0;
        if(prev == -1 || nums[ind] > nums[prev]) {
            take = 1 + solve(ind + 1, ind, nums, dp);
        }

        return dp[ind][prev + 1] = max(take, notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n + 1, -1)); 

        return solve(0, -1, nums, dp);
    }
};
// Complexity
// Time: O(n²)
// Space: O(n²) + O(n) recursion stack

// DP Tabulation (Bottom-Up)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, 1);

        int ans = 1;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};
// Complexity
// Time: O(n²)
// Space: O(n)
