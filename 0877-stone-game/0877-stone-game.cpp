class Solution {
public:
        vector<vector<int>>dp;
    int solve(int left, int right, vector<int>& piles){

        if(left == right){
            return piles[left];
        }
        if (dp[left][right] != -1)
            return dp[left][right];


        int takenleft = piles[left] - solve(left+1, right, piles);
        int takenright = piles[right] - solve(left, right-1, piles);
        return dp[left][right] =  max(takenleft, takenright);
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        dp.resize(n, vector<int>(n, -1));

        return solve(0, n - 1, piles) > 0;
        // we can simply return true and it passes all the test cases !!
    }
};