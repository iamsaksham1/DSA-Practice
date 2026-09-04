class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> stb(n);
        stb[0] = nums[0];

        //creating stb of maximum from nums
        for(int i = 1; i< n; i++){
            stb[i] = max(nums[i], stb[i-1]);
        }

        //traversing from last of nums to find the minimum number
            int minNum = INT_MAX;
            for(int i = n-1; i>=0; i--){
                minNum = min(minNum, nums[i]);
                stb[i] -= minNum;
            }

            for( int i = 0; i< n; i++){
                if(stb[i] <= k)
                return i;
            }
            return -1;
        
    }
};