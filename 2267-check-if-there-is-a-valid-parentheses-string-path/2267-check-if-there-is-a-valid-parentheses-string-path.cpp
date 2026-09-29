class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;

    bool solve(int i, int j, int balance, vector<vector<char>>& grid) {

        // Process current cell first
        if (grid[i][j] == '(')
            balance++;
        else
            balance--;

        // Balance can never become negative
        if (balance < 0)
            return false;

        // Number of cells remaining AFTER current cell
        int remaining = (m - i - 1) + (n - j - 1);

        // Not enough cells left to close all '('
        if (balance > remaining)
            return false;

        // Destination
        if (i == m - 1 && j == n - 1)
            return balance == 0;

        // DP
        if (dp[i][j][balance] != -1)
            return dp[i][j][balance];

        bool ans = false;

        // Move down
        if (i + 1 < m)
            ans |= solve(i + 1, j, balance, grid);

        // Move right
        if (j + 1 < n)
            ans |= solve(i, j + 1, balance, grid);

        return dp[i][j][balance] = ans;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // Path length must be even
        if ((m + n - 1) % 2 != 0)
            return false;

        // First character must be '('
        if (grid[0][0] != '(')
            return false;

        dp.assign(
            m,
            vector<vector<int>>(
                n,
                vector<int>(m + n + 1, -1)
            )
        );

        return solve(0, 0, 0, grid);
    }
};