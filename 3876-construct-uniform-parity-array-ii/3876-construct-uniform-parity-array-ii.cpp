class Solution {
public:
    bool uniformArray(vector<int>& nums1) {

        // finding the minimum of the arr
        int minimum = nums1[0];
        for(int i=0; i<nums1.size(); i++){
            minimum = min(nums1[i], minimum);
        }

        // checking if the minimum is odd or not 
        if(minimum % 2 == 1 ){
            return true;
        }
        // then, minimum is even
        // Search for an odd number
        for( int x : nums1){
            if( x % 2 == 1){
                return false ;
            }
        }
        return true;
    }
};