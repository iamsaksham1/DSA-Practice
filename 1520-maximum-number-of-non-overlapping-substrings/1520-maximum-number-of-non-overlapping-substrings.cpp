class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
// ai coded
        int n = s.size();

        vector<int> first(26, n);
        vector<int> last(26, -1);

        // Find first and last occurrence of every character
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';

            first[c] = min(first[c], i);
            last[c] = i;
        }

        // Store valid intervals [left, right]
        vector<pair<int, int>> intervals;

        // Try starting from the first occurrence of every character
        for (int c = 0; c < 26; c++) {

            if (last[c] == -1)
                continue;

            int left = first[c];
            int right = last[c];

            bool valid = true;

            for (int i = left; i <= right; i++) {

                int x = s[i] - 'a';

                // This character appeared before our left boundary
                if (first[x] < left) {
                    valid = false;
                    break;
                }

                // Need to include all occurrences of this character
                right = max(right, last[x]);
            }

            if (valid) {
                intervals.push_back({left, right});
            }
        }

        // Sort by ending position
        sort(intervals.begin(), intervals.end(),
            [](pair<int,int>& a, pair<int,int>& b) {
                if (a.second == b.second)
                    return a.first > b.first;
                return a.second < b.second;
            });

        vector<string> ans;
        int prevEnd = -1;

        // Greedily choose non-overlapping intervals
        for (auto interval : intervals) {

            int left = interval.first;
            int right = interval.second;

            if (left > prevEnd) {
                ans.push_back(s.substr(left, right - left + 1));
                prevEnd = right;
            }
        }
        return ans;
    }
};