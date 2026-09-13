class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int maxcount = 0;

        // try every possible translation
        for (int x = -(n - 1); x < n; x++) {
            for (int y = -(n - 1); y < n; y++) {
                int count = 0;

                // check every position in img1
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        int nx = i + x;
                        int ny = j + y;

                        // check whether translated position is inside img2
                        if (nx >= 0 && nx < n &&
                            ny >= 0 && ny < n) {
                            if (img1[i][j] == 1 && img2[nx][ny] == 1) {
                                count++;
                            }
                        }
                    }
                }
                maxcount = max(maxcount, count);
            }
        }
        return maxcount;
    }
};