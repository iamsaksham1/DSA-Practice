class Solution {
public:
    int maximumLengthSubstring(string s) {

        unordered_map<char, int> freq;

        int left = 0;
        int ans = 0;

        for (int right = 0; right < s.size(); right++) {

            freq[s[right]]++;

            // If current character occurs more than 2 times,
            // shrink the window.
            while (freq[s[right]] > 2) {
                freq[s[left]]--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};