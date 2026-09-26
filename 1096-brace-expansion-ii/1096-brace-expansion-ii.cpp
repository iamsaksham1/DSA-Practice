class Solution {
public:
    string s;
    int i = 0;

    set<string> parseExpr() {
        set<string> res = parseTerm();

        while (i < s.size() && s[i] == ',') {
            i++;
            set<string> temp = parseTerm();
            res.insert(temp.begin(), temp.end());
        }

        return res;
    }

    set<string> parseTerm() {
        set<string> res = {""};

        while (i < s.size() && s[i] != '}' && s[i] != ',') {
            set<string> cur = parseFactor();

            set<string> temp;

            for (string a : res) {
                for (string b : cur) {
                    temp.insert(a + b);
                }
            }

            res = temp;
        }

        return res;
    }

    set<string> parseFactor() {
        set<string> res;

        if (s[i] == '{') {
            i++; // skip {

            res = parseExpr();

            i++; // skip }
        }
        else {
            res.insert(string(1, s[i]));
            i++;
        }

        return res;
    }

    vector<string> braceExpansionII(string expression) {
        s = expression;
        i = 0;

        set<string> ans = parseExpr();

        return vector<string>(ans.begin(), ans.end());
    }
};