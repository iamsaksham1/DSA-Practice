class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        // Prefix sum
        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        // dp[i][j] = maximum score from subarray [i...j]
        vector<vector<int>> dp(n, vector<int>(n, -1));

        function<int(int, int)> solve = [&](int i, int j) -> int {

            // Only one stone
            if (i >= j)
                return 0;

            // Already calculated
            if (dp[i][j] != -1)
                return dp[i][j];

            int ans = 0;

            int leftSum = 0;
            int rightSum = prefix[j + 1] - prefix[i];

            for (int k = i; k < j; k++) {

                // Move one stone from right to left
                leftSum += stoneValue[k];
                rightSum -= stoneValue[k];

                // Left side is smaller
                if (leftSum < rightSum) {

                    ans = max(ans,
                              leftSum + solve(i, k));
                }

                // Right side is smaller
                else if (leftSum > rightSum) {

                    ans = max(ans,
                              rightSum + solve(k + 1, j));
                }

                // Both sides are equal
                else {

                    ans = max(ans,
                              max(leftSum + solve(i, k),
                                  rightSum + solve(k + 1, j)));
                }
            }

            return dp[i][j] = ans;
        };

        return solve(0, n - 1);
    }
};