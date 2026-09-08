class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int count = 0;
        
        while(true){
            //checking if nums is sorted or not
            bool sorted = true;
            for(int i =0; i<nums.size()- 1; i++){
                if(nums[i]>nums[i+1]){
                    sorted = false;
                    break;
                }
            }
            if(sorted){
                return count;
            }
            // finding adjacent pair with minimum sum so that we can 
            // replace the index val with the sum
            int minsum = INT_MAX;
            int index = 0;
            for(int i =0; i+1 <nums.size(); i++){
                int sum = nums[i]+nums[i+1];

                if(sum<minsum){
                    minsum = sum;
                    index =i;
                }
            }
            // merging the pair with the index and sum
            nums[index] = minsum;
            nums.erase(nums.begin() + index+1);
            count ++;
        }
    }
};