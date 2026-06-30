class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low =0;
        int high = nums.size()-1;
        int first = -1;
        while(low<=high){
            int mid = low + (high - low) / 2;
            if(nums[mid] < target){
                low= mid+1;
            }
            else if (nums[mid] > target) {
                high = mid - 1;
                }
                else{
                    first =mid;    
                    high =mid-1;  //search toward right
                }
        }
        // First occurrence is already found

int last = -1;

low = 0;
high = nums.size() - 1;

while(low <= high)
{
    int mid = low + (high - low) / 2;

    if(nums[mid] < target)
    {
        low = mid + 1;
    }
    else if(nums[mid] > target)
    {
        high = mid - 1;
    }
    else
    {
        last = mid;
        low = mid + 1;     // Search towards the right
    }
}

return {first, last};

    }
};