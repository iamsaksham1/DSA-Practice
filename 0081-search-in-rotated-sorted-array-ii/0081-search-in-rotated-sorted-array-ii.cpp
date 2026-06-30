class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low =0;
        int high =nums.size()-1;

        while(low<=high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target){
            return true;
            }
            if(nums[low]==nums[mid] && nums[high]==nums[mid]){
                low++;
                high--;
            }
            else if(nums[low]<=nums[mid]){  // Left half is sorted
                if(target>=nums[low] && target<nums[mid]){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            else {
                if(target<=nums[high] && target>nums[mid]){
                    low = mid + 1;
                }
                else{
                    high = mid-1;
                }
            }  
        }
        return false;
    }
};