class Solution {
public:
    int smallestNumber(int n, int t) {

        while (true) {
            int number = n;
            int prod = 1;

            while (number > 0) {
                int digit = number % 10;
                prod *= digit;
                number /= 10;
            }

            if (prod % t == 0) {
                return n;
            }

            n++;
        }
    }
};