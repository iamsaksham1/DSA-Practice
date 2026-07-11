class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        //need at least 3 numbers, so it should stop earlier:
        for(int i=0; i<nums.size()-2; i++){

            // Skip duplicate first element
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int second =i+1;
            int last = nums.size()-1;
            while(second<last){
            int sum = nums[i] + nums[second] + nums[last];
            if(sum == 0){
                res.push_back({nums[i] , nums[second] , nums[last]});
                second ++;
                last --;
                // Skip duplicate second
                    while (second < last &&
                           nums[second] == nums[second - 1])
                        second++;

                    // Skip duplicate last
                    while (second < last &&
                           nums[last] == nums[last + 1])
                        last--;
            }

            else if(sum<0){
                second ++;
            }
            else if(sum>0){
                last--;
            }
          }
        }
        return res;
    }
};