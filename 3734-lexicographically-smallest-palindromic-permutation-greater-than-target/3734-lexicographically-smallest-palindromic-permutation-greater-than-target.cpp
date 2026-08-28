class Solution {
public:

    string makePalindrome(string half, char middle) {
        string ans = half;

        if (middle != '#')
            ans += middle;

        reverse(half.begin(), half.end());
        ans += half;

        return ans;
    }

    string lexPalindromicPermutation(string s, string target) {

        int n = s.size();

        // Count characters
        vector<int> cnt(26, 0);

        for (char c : s)
            cnt[c - 'a']++;

        // Check whether palindrome is possible
        int odd = 0;
        char middle = '#';

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
                middle = char('a' + i);
            }
        }

        if (odd > 1)
            return "";

        // Characters available for the left half
        vector<int> halfCnt(26);

        for (int i = 0; i < 26; i++)
            halfCnt[i] = cnt[i] / 2;

        int halfLen = n / 2;

        string prefix = target.substr(0, halfLen);

        vector<int> rem = halfCnt;
        string half = "";

        int i;

        // Try to make the half equal to target's half
        for (i = 0; i < halfLen; i++) {

            int x = prefix[i] - 'a';

            if (rem[x] == 0)
                break;

            half += prefix[i];
            rem[x]--;
        }
        // CASE 1:
        // We matched the entire first half.
        if (i == halfLen) {

            string pal = makePalindrome(half, middle);

            // If already greater than target
            if (pal > target)
                return pal;

            // Need the next permutation of half
            int j = halfLen - 2;

            while (j >= 0 && half[j] >= half[j + 1])
                j--;

            if (j < 0)
                return "";

            int k = halfLen - 1;

            while (half[k] <= half[j])
                k--;

            swap(half[j], half[k]);

            reverse(half.begin() + j + 1, half.end());

            return makePalindrome(half, middle);
        }
        // CASE 2:
        // We couldn't match target[i].
        // Try making position i bigger.

        for (int j = i; j >= 0; j--) {

            // If j is a previously matched position,
            // put its character back.
            if (j < i)
                rem[half[j] - 'a']++;

            int targetChar = prefix[j] - 'a';

            // Find smallest character > target[j]
            for (int c = targetChar + 1; c < 26; c++) {

                if (rem[c] > 0) {

                    string result = half.substr(0, j);

                    result += char('a' + c);

                    rem[c]--;

                    // Fill remaining characters smallest first
                    for (int x = 0; x < 26; x++) {
                        while (rem[x] > 0) {
                            result += char('a' + x);
                            rem[x]--;
                        }
                    }

                    return makePalindrome(result, middle);
                }
            }
        }

        return "";
    }
};