class Solution {
public:
    int func(int i, int j, vector<vector<int>> &dp, vector<vector<int>>& obstacleGrid) {
        if (i == 0 && j == 0) {
            return obstacleGrid[0][0] == 1 ? 0 : 1;
        }

        if (i < 0 || j < 0 || obstacleGrid[i][j] == 1) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int up = func(i - 1, j, dp, obstacleGrid);
        int left = func(i, j - 1, dp, obstacleGrid);

        return dp[i][j] = up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        return func(m - 1, n - 1, dp, obstacleGrid);
    }
};
