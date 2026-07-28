class Solution {
public:
    bool isValid(string s) {
        size_t pos;

        while((pos = s.find("()")) != string::npos ||
        (pos = s.find("{}"))  != string::npos ||
        (pos = s.find("[]"))  != string::npos) {
            s.erase(pos, 2);
        }
        return s.empty();
    }
};