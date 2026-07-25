class Solution {
public:
    string addBinary(string a, string b) {
        int sum =0;
        string ans="";
        int i = a.size()-1;
        int j= b.size()-1;
        int carry =0;
        while (i >= 0 || j >= 0 || carry) {
            int bitA = 0;
            int bitB = 0;
            if(i>=0){
                bitA = a[i] - '0';
            }
            if(j>=0){
                bitB = b[j] - '0';
            }
            sum = bitA + bitB + carry;
            carry = sum /2;
            char bit = '0' + (sum % 2);
            ans += bit;
            i--;
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};