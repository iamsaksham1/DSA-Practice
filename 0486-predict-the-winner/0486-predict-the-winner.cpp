class Solution {
public:
int solve(int left, int right, vector<int>& nums){
            if( left== right){
                return nums[left];
            }
            int takeleft = nums[left] - solve(left + 1, right, nums);
            int takeright = nums[right] - solve(left, right - 1, nums);
            return max(takeleft, takeright);
        }
    bool predictTheWinner(vector<int>& nums) {
        
        
        int n = nums.size();
        int ans = solve(0, n-1, nums);
        if( ans>=0){
            return true;
        }
        else {
            return false;
        }
        
    }
};