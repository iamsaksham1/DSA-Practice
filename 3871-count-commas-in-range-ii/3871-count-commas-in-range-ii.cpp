class Solution {
public:
    long long countCommas(long long n) {
        long long res = 0;
        long long digits = 1000;

        while(digits <= n){
            res += n - digits +1 ;
            digits *= 1000;
        }
        return res;
    }
};