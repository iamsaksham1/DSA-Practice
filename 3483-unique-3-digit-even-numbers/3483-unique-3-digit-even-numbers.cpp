class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        // 1. building three digits number we need
        // hundreds tens units

        // 2. conditions 
        // * hundred digits can not be 0
        // * last digit must be even
        // * number must be distinct

        int n = digits.size();
        set<int>s;

        for( int i=0; i<n; i++){
            if(digits[i]==0)
            continue;

            for(int j=0; j<n; j++){
                if(j==i)
                continue;

                for(int k=0; k<n; k++){
                    if(k==i || k==j)
                    continue;

                    if(digits[k]%2 != 0)
                    continue;

                    int num = digits[i]*100 + digits[j]*10 + digits[k];

                    s.insert(num);
                }
            }
        }
        return s.size();
    }
};