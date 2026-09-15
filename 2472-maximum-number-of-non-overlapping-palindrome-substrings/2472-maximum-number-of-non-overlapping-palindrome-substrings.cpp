class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        // dp[j][i] = is s[j...i] a palindrome???
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {

                if (s[j] == s[i]) {
                    if (i - j <= 1)
                        dp[j][i] = true;
                    else
                        dp[j][i] = dp[j + 1][i - 1];
                }
            }
        }

        // ans[i] = maximum number of non=overlapping
        // palindromes using first i characters
        vector<int> ans(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            ans[i] = ans[i - 1];

            for (int j = 0; j < i; j++) {

                // s[j...i-1] is a palindrome
                // and its length is at least k
                if (dp[j][i - 1] && i - j >= k) {
                    ans[i] = max(ans[i], ans[j] + 1);
                }
            }
        }

        return ans[n];
    }
};