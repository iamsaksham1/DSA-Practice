class Solution {
public:
    vector<int> validSequence(string word1, string word2) {

        int n = word1.size();
        int m = word2.size();

        vector<int> ans(m);

        // last[j] = last index in word1
        // where word1[index] == word2[j]
        vector<int> last(m, -1);

        // Find the latest possible positions
        // for matching word2 from the right.
        int i = n - 1;
        int j = m - 1;

        while (i >= 0 && j >= 0) {

            if (word1[i] == word2[j]) {
                last[j] = i;
                j--;
            }

            i--;
        }

        // We can use at most ONE mismatch.
        bool canSkip = true;

        j = 0;

        for (i = 0; i < n; i++) {

            if (j == m)
                break;

            // Case 1: Exact match
            if (word1[i] == word2[j]) {

                ans[j] = i;
                j++;
            }

            // Case 2: Use our one allowed mismatch
            else if (canSkip &&
                     (j == m - 1 || i < last[j + 1])) {

                ans[j] = i;
                j++;

                canSkip = false;
            }
        }

        // Did we find m indices?
        if (j == m)
            return ans;

        return {};
    }
};