class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum =0;
        int maxSum =0;
        for(int i=0; i<k; i++){
            sum+=nums[i];
        }
        maxSum = sum;
        for(int j=k; j<nums.size(); j++){
            sum-=nums[j-k];
            sum+=nums[j];

            maxSum = max(sum, maxSum);
        }

        return (double)maxSum / k;
    }
};