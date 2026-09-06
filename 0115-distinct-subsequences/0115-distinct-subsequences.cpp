class Solution {
public:
    int numDistinct(string s, string t) {

        int n = s.size();
        int m = t.size();

        // dp[i][j] =
        // number of ways to form t[0...j-1]
        // using s[0...i-1]
        vector<vector<unsigned long long>> dp(
            n + 1,
            vector<unsigned long long>(m + 1, 0)
        );

        // Empty string t can always be formed
        // by deleting all characters from s.
        dp[0][0] = 1;

        // For any s, there is exactly 1 way
        // to form an empty t: choose nothing.
        for (int i = 1; i <= n; i++) {
            dp[i][0] = 1;
        }

        // Start considering characters of s and t
        for (int i = 1; i <= n; i++) {

            for (int j = 1; j <= m; j++) {

                // If current characters match
                if (s[i - 1] == t[j - 1]) {

                    // We have TWO choices:
                    //
                    // 1. Use s[i-1]
                    //    -> dp[i-1][j-1]
                    //
                    // 2. Don't use s[i-1]
                    //    -> dp[i-1][j]
                    //
                    dp[i][j] = dp[i - 1][j - 1]
                             + dp[i - 1][j];

                }
                else {

                    // Characters don't match.
                    // We cannot use s[i-1],
                    // so simply ignore it.
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        // Number of ways to form all of t
        // using all of s
        return dp[n][m];
    }
};