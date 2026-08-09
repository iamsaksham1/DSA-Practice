class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        // suffix[i] = total stones from i to n-1
        vector<int> suffix(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }

        // dp[i][M] = maximum stones Alice can get
        // starting from index i with current M
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int M = 1; M <= n; M++) {

                // If we can take all remaining piles
                if (2 * M >= n - i) {
                    dp[i][M] = suffix[i];
                    continue;
                }

                int best = 0;

                // Try taking X piles
                for (int X = 1; X <= 2 * M; X++) {

                    // Alice takes X piles
                    // Bob then gets the optimal result from i+X
                    int alice = suffix[i] - dp[i + X][max(M, X)];

                    best = max(best, alice);
                }

                dp[i][M] = best;
            }
        }

        return dp[0][1];
    }
};