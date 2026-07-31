class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        vector<int> freq(26,0);
        
        for(char c: word){
            freq[c-'a']++;
        }
        int ans =0; int cost =0;
        sort(freq.begin(), freq.end(), greater<int>());
        for(int i=0; i<freq.size(); i++){
            cost=(i/8)+1;
           ans += cost * freq[i];
        }
        return ans;
    }
};