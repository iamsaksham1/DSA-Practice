class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int left = 0;
        int ones = 0;
        string ans = "";

        for (int right = 0; right < s.size(); right++) {

            // Add current character
            if (s[right] == '1')
                ones++;

            // Too many 1s -> move left
            while (ones > k) {
                if (s[left] == '1')
                    ones--;
                left++;
            }

            // Remove unnecessary 0s from the left ohkk
            while (ones == k && s[left] == '0') {
                left++;
            }

            // We have exactly k ones
            if (ones == k) {
                string current = s.substr(left, right - left + 1);

                // Choose krna hai |||
                // Shorter string
                // If same length, lexicographically smaller
                if (ans == "" ||
                    current.size() < ans.size() ||
                    (current.size() == ans.size() && current < ans)) {

                    ans = current;
                }
            }
        }

        return ans;
    }
};