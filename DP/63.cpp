class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        bool blk;
        long long dp[row][col];

        blk = true;
        for (int i = 0; i < col; i++){
            if (obstacleGrid[0][i] == 0 && blk){
                dp[0][i] = 1;
            }
            else{
                dp[0][i] = 0;
                blk = false;
            }
        }
        if (row == 1){
            if (blk)
                return 1;
            else return 0;
        }

        blk = true;
        for (int i = 0; i < row; i++){
            if (obstacleGrid[i][0] == 0 && blk){
                dp[i][0] = 1;
            }
            else{
                dp[i][0] = 0;
                blk = false;
            }
        }
        if (col == 1){
            if (blk)
                return 1;
            else return 0;
        }

        for (int i = 1; i < row; i++){
            for (int j = 1; j < col; j++){
                if (obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                }
                else{
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        
        return dp[row-1][col-1];
    }

};