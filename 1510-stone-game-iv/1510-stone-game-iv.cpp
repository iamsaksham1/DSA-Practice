class Solution {
public:
    bool winnerSquareGame(int n) {

        vector<bool> dp(n + 1, false);

        // dp[0] = false
        // No stones -> current player loses

        for (int i = 1; i <= n; i++) {

            for (int j = 1; j * j <= i; j++) {

                int square = j * j;

                // If Bob gets a losing position,
                // Alice can win by taking this square.
                if (dp[i - square] == false) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};