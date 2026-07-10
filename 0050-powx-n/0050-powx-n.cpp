class Solution {
public:
    double myPow(double x, int n) {
        long long m=n;
       double ans =1;
       if(m<0){
        x = 1/x;
        m=-m;
       }
       while(m>0){
        if(m %2 != 0){
            ans*=x;
        }
        
            x*=x;
            m/=2;
        
       }
       return ans;
    }
};