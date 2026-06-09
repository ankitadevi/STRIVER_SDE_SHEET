// recurrsion
int solve(int i, int j,
          string& s1,
          string& s2){

    if(i == s1.size() || j == s2.size())
        return 0;

    if(s1[i] == s2[j])
        return 1 + solve(i+1,j+1,s1,s2);

    return max(
        solve(i+1,j,s1,s2),
        solve(i,j+1,s1,s2)
    );
}
// memo
class Solution {
public:

    int solve(int i, int j,
              string& s1,
              string& s2,
              vector<vector<int>>& dp){

        if(i == s1.size() || j == s2.size())
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(s1[i] == s2[j]){

            return dp[i][j] =
                1 + solve(i+1,j+1,s1,s2,dp);
        }

        return dp[i][j] =
            max(
                solve(i+1,j,s1,s2,dp),
                solve(i,j+1,s1,s2,dp)
            );
    }

    int lcs(string str1, string str2) {

        int n = str1.size();
        int m = str2.size();

        vector<vector<int>> dp(
            n,
            vector<int>(m,-1)
        );

        return solve(
            0,0,
            str1,str2,
            dp
        );
    }
};
// tab
class Solution {
public:

    int lcs(string str1, string str2) {

        int n = str1.size();
        int m = str2.size();

        vector<vector<int>> dp(
            n + 1,
            vector<int>(m + 1, 0)
        );

        for(int i = 1; i <= n; i++){

            for(int j = 1; j <= m; j++){

                if(str1[i-1] == str2[j-1]){

                    dp[i][j] =
                        1 + dp[i-1][j-1];
                }
                else{

                    dp[i][j] =
                        max(dp[i-1][j],
                            dp[i][j-1]);
                }
            }
        }

        return dp[n][m];
    }
};

// | Approach        | Time       | Space         |
// | --------------- | ---------- | ------------- |
// | Recursion       | O(2^(n+m)) | O(n+m)        |
// | Memoization     | O(n*m)     | O(n*m)+O(n+m) |
// | Tabulation      | O(n*m)     | O(n*m)        |
// | Space Optimized | O(n*m)     | O(m)          |
