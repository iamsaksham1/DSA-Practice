class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> cnt(26, 0);

        // Count characters of s
        for (char c : s) {
            cnt[c - 'a']++;
        }

        string ans = "";

        for (int i = 0; i < target.size(); i++) {

            // Try to put the same character as target[i]
            if (cnt[target[i] - 'a'] > 0) {
                ans += target[i];
                cnt[target[i] - 'a']--;
            }
            else {
                // We cannot continue with equality.
                // Try a character greater than target[i].
                for (int c = target[i] - 'a' + 1; c < 26; c++) {

                    if (cnt[c] > 0) {
                        ans += char('a' + c);
                        cnt[c]--;

                        // Put all remaining characters
                        // in smallest possible order.
                        for (int x = 0; x < 26; x++) {
                            while (cnt[x] > 0) {
                                ans += char('a' + x);
                                cnt[x]--;
                            }
                        }

                        return ans;
                    }
                }

                // No greater character here.
                // We need to go backwards and make an
                // earlier position greater.
                for (int j = i - 1; j >= 0; j--) {

                    // Put target[j] back into available characters
                    cnt[target[j] - 'a']++;

                    // Try a character greater than target[j]
                    for (int c = target[j] - 'a' + 1; c < 26; c++) {

                        if (cnt[c] > 0) {

                            string result = target.substr(0, j);

                            result += char('a' + c);
                            cnt[c]--;

                            // Fill remaining characters
                            // in smallest order.
                            for (int x = 0; x < 26; x++) {
                                while (cnt[x] > 0) {
                                    result += char('a' + x);
                                    cnt[x]--;
                                }
                            }

                            return result;
                        }
                    }
                }

                return "";
            }
        }

        // s can make exactly target,
        // but we need STRICTLY greater.
        // So go backwards and increase some position.
        for (int j = target.size() - 1; j >= 0; j--) {

            cnt[target[j] - 'a']++;

            for (int c = target[j] - 'a' + 1; c < 26; c++) {

                if (cnt[c] > 0) {

                    string result = target.substr(0, j);

                    result += char('a' + c);
                    cnt[c]--;

                    for (int x = 0; x < 26; x++) {
                        while (cnt[x] > 0) {
                            result += char('a' + x);
                            cnt[x]--;
                        }
                    }

                    return result;
                }
            }
        }

        return "";
    }
};