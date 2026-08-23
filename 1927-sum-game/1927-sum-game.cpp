class Solution {
public:
    bool sumGame(string nums) {
        int n = nums.length();
        int half = n>>1;
        int L = 0, R = 0, diff = 0;

        for(int i=0; i<n; i++){
            if(i<half){
                if(nums[i] == '?'){
                    L++;
                }
                else{
                    diff += nums[i] - '0';
                }
            }
            else{
                if(nums[i] == '?'){
                    R++;
                }
                else{
                    diff -= nums[i]- '0';
                }
            }
        }
        if((L + R) & 1){
            return true;
        }

        return diff != 9*(R - L) >> 1;
    }
};