class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        string ans = "";

        for (int i=0; i<s[0].size(); i++){ //character position
            char ch = s[0][i];
            for(int j=1; j<s.size(); j++){ //string number
            if(i>=s[j].size() || s[j][i] != ch){
                //prefix ended 
                return ans;
            }
            }
            ans += ch;
        }
        return ans;
    }
};