class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int piv = -1; int n = nums.size();

        // finding the pivot element
        for(int i=n-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                piv = i;
                break;
            }
        }
        if(piv == -1){
            reverse(nums.begin(),nums.end()); // STL function
            return;
        }
        // finding next larger element
        for(int j= n-1; j>=0; j--){
            if(nums[j]>nums[piv]){
            swap(nums[j], nums[piv]);
            break;}
        }
        int i= piv+1;
        int j=n-1;
        while(i<=j){
            swap(nums[i],nums[j]);
            i++;
            j--;
        }


    }
};