class Solution {
public:

    struct State {
        long long score = 0;
        vector<int> indices;
    };

    // Return the better of two states
    State better(State a, State b) {
        if (a.score != b.score)
            return (a.score > b.score) ? a : b;

        // Same score => lexicographically smaller indices
        if (a.indices < b.indices)
            return a;

        return b;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();

        // Add original index
        // [start, end, weight, index] that is it...
        vector<vector<int>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort by ending position
        sort(a.begin(), a.end(),
             [](const vector<int>& x, const vector<int>& y) {
                 return x[1] < y[1];
             });

        // Store end positions for binary search
        vector<int> ends(n);

        for (int i = 0; i < n; i++) {
            ends[i] = a[i][1];
        }

        // prev[i] = number of intervals before i
        // whose end < a[i].start
        vector<int> prev(n);

        for (int i = 0; i < n; i++) {

            prev[i] = lower_bound(
                ends.begin(),
                ends.begin() + i,
                a[i][0]
            ) - ends.begin();
        }

        // dp[i][k]
        // best answer using first i intervals
        // while selecting at most k intervals
        vector<vector<State>> dp(n + 1, vector<State>(5));

        for (int i = 1; i <= n; i++) {

            // Donot take current interval
            for (int k = 0; k <= 4; k++) {
                dp[i][k] = dp[i - 1][k];
            }
            // Take current interval
            for (int k = 1; k <= 4; k++) {

                State take = dp[prev[i - 1]][k - 1];
                take.score += a[i - 1][2];
                take.indices.push_back(a[i - 1][3]);
                sort(take.indices.begin(), take.indices.end());
                dp[i][k] = better(dp[i][k], take);
            }
        }

        return dp[n][4].indices;
    }
};