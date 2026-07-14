class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n =matrix[0].size();
        bool firstColZero =false;

        // Step 1: Check whether the first column
        // originally contains any zero.
        for(int i=0; i<m; i++){
            if (matrix[i][0] == 0)
            firstColZero = true;

            //Step 2: Use the first row and
            // first column as markers.
            for(int j=1; j<n; j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }

        // Step 3: Zero out the matrix
        // based on the stored markers.
        // (Skip first row and first column)
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(matrix[0][j]==0 || matrix[i][0]==0){
                    matrix[i][j]=0;
                }
            }
        }

        // Step 4: If matrix[0][0] is 0,
        // make the entire first row zero.
        if(matrix[0][0]==0){
            for(int j=0; j<n; j++){
                matrix[0][j]=0;
            }
        }

        // Step 5: If the first column
        // originally had a zero,
        // make the entire first column zero.
        if (firstColZero == true){
            for(int i=0; i<m; i++){
                matrix[i][0]=0;
            }
        }
    }
};