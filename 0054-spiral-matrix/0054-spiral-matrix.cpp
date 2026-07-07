class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int sr = 0 , er = m-1 , sc = 0, ec = n-1; //starting row,col and ending row,col
        vector<int>res;
        // top => right => left => right
        while(sr<=er && sc<=ec){
            //Top
            for(int j=sc; j<=ec; j++){
                res.push_back(matrix[sr][j]);
            }
            // Right
            for(int i=sr+1; i<=er; i++){
                res.push_back(matrix[i][ec]);
            }
            // Bottom
            for(int k=ec-1; k>=sc; k--){
                if(sr == er){
                    break;
                }
                res.push_back(matrix[er][k]);
            }
            // Left
            for(int l=er-1; l>sr; l--){
                if(sc == ec){
                    break;
                }
                res.push_back(matrix[l][sc]);
            }
            sr++; er--; sc++; ec--;
        }
        return res;

    }
};