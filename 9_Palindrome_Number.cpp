/*
Palindrome Number
Given an integer x, return true if x is a palindrome, and false otherwise.
*/

class Solution {
public:
    bool isPalindrome(int x) {
        bool palindrome = false;
        long long rev = 0;
        long long digits = 0;
        long long orignal = x;
        if(x < 0)
        return false;
        while( x > 0){
            digits = x%10;
            rev = rev*10 + digits;
            x/=10;
        }
        if(rev==orignal){
            palindrome = true;
        }
        
        return palindrome;
    }
};