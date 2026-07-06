class Solution {
public:
// function to search individual row
bool search_in_row(vector<vector<int>>& matrix, int target, int row){
    int low = 0;
    int high = matrix[0].size() -1;
    while(low<=high){
        int mid = low + (high - low)/2;
        if(target == matrix[row][mid]){
            return true;
        }
        else if(target>matrix[row][mid]){
            low = mid +1;
        }
        else{
            high = mid -1;
        }
    }
    return false;
}
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int m = matrix.size(), n = matrix[0].size();
       int sr =0; //starting row
       int er =m-1; //ending row
       while(sr<=er){
        int midr = sr + (er - sr)/2; // mid row
        if(target >= matrix[midr][0] && target <= matrix[midr][n-1]){
            // again binary search for the target
            return search_in_row(matrix, target, midr);
        }
        else if(target > matrix[midr][n-1]){
            // go down to search
            sr = midr +1;
        }
        else{
            // go up to search
            er = midr -1;
        }
       } 
       return false;
    }
};