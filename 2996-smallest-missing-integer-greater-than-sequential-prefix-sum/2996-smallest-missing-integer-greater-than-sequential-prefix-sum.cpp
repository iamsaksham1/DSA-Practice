class Solution {
public:
    int missingInteger(vector<int>& nums) {
        vector<bool>exist(52);
        for(int i=0; i<nums.size(); i++){
            exist[nums[i]]=true;
        }

        int sum = nums[0];
        for(int j=1; j<nums.size(); j++){
            if(nums[j] == nums[j-1] +1){
                sum += nums[j];
            }
            else break;
        }
        if(sum>=52){
            return sum;
        }
        for( int k=sum; k<=51; k++){
            if(exist[k] !=true){
                return k;
            }
        }
        return 0;
    }
};