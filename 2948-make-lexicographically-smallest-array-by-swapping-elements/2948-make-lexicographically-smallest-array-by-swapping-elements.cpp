class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {

        int n = nums.size();

        // Keep original positions
        vector<pair<int, int>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({nums[i], i});
        }

        // Sort by value
        sort(a.begin(), a.end());

        int start = 0;

        while (start < n) {

            int end = start;

            // Find one connected group
            while (end + 1 < n &&
                   a[end + 1].first - a[end].first <= limit) {
                end++;
            }

            // Collect original indices of this group
            vector<int> indices;

            for (int i = start; i <= end; i++) {
                indices.push_back(a[i].second);
            }

            // Sort original positions
            sort(indices.begin(), indices.end());

            // Put smallest values at smallest positions
            for (int i = 0; i < indices.size(); i++) {
                nums[indices[i]] = a[start + i].first;
            }

            start = end + 1;
        }

        return nums;
    }
};