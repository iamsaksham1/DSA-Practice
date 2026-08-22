class Solution {
public:
    bool checkDivisibility(int n) {
       int sum =0;
       int prod = 1;
       int temp = n;
       while (temp){
        sum+=temp%10;
        prod*=temp%10;
        temp/=10;
       }
       return n % (sum + prod) == 0;
    }
};