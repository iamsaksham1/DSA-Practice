class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            int reversedValue = 26 - (s[i] - 'a');
            int position = i + 1;
            ans += reversedValue * position;
        }
        return ans;
    }
};