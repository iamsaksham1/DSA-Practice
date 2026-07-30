class Solution {
public:
    int minimumPushes(string w) {
        int cost =0;
        for(int i=0; i<w.length(); i++){
            cost+= (i/8)+1;
        }
        return cost; 
    }
};