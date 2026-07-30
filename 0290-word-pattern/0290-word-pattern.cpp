class Solution {
public:
    bool wordPattern(string ptrn, string s) {
        vector<string> words;
        stringstream ss(s);
        string word;
        while (ss >> word) {
            words.push_back(word);
            }
            if(words.size() != ptrn.size()){
                return false;
            }

            unordered_map<char, string>m1;
            unordered_map<string, char>m2;

            for(int i=0; i<ptrn.length(); i++){
                if(m1.count(ptrn[i]) && m1[ptrn[i]]!= words[i]){
                    return false;
                }
                if(m2.count(words[i]) && m2[words[i]]!=ptrn[i]){
                    return false;
                }
                m1[ptrn[i]]=words[i];
                m2[words[i]]=ptrn[i];
            }
            return true;
    }
};