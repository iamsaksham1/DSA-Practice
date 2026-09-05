class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {

        int n = nums.size();

        // stb[i] will store:
        // maximum value from nums[0] to nums[i]
        vector<int> stb(n);

        // Initialize the first prefix maximum
        stb[0] = nums[0];

        // Build prefix maximum array
        for (int i = 1; i < n; i++) {
            stb[i] = max(stb[i - 1], nums[i]);
        }

        // Find suffix minimum and calculate
        // instability score for every index
        int minNum = INT_MAX;

        for (int i = n - 1; i >= 0; i--) {

            // Minimum from nums[i] to nums[n-1]
            minNum = min(minNum, nums[i]);

            // instability score =
            // prefix maximum - suffix minimum
            stb[i] = stb[i] - minNum;
        }

        // Find the smallest stable index
        for (int i = 0; i < n; i++) {

            if (stb[i] <= k) {
                return i;
            }
        }

        // No stable index exists
        return -1;
    }
};