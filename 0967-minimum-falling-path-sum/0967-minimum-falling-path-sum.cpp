class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        
        for (int j = 0; j < n; ++j) {
            dp[0][j] = matrix[0][j];
        }

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int left, up, right;

                if (j > 0) {
                    left = dp[i-1][j-1];
                } else {
                    left = INT_MAX;
                }

                up = dp[i-1][j];

                if (j < n - 1) {
                    right = dp[i-1][j+1];
                } else {
                    right = INT_MAX;
                }

                dp[i][j] = matrix[i][j] + min({left, up, right});
            }
        }
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            mini=min(dp[n-1][i],mini);
        }
        return mini;
        
    }
};


//Memoization
//Time Limit Exceeded
//49 / 52 testcases passed
// class Solution {
// public:
//     int func(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j) {
//         int n = matrix.size();
//         if (j < 0 || j >= n || i<0) {
//             return INT_MAX;
//         }
//         if (i == 0) {
//             return matrix[i][j];
//         }
//         if (dp[i][j] != -1) {
//             return dp[i][j];
//         }
//         int left = func(matrix, dp, i-1, j-1);
//         int right = func(matrix, dp, i-1, j+1);
//         int up = func(matrix, dp, i-1, j);
        
//         return dp[i][j] = matrix[i][j] + min({left, right, up});
//     }

//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         vector<vector<int>> dp(n, vector<int>(n, -1));
//         int ans = INT_MAX;

//         for (int j = 0; j < n; ++j) {
//             ans = min(ans, func(matrix, dp, n-1, j));
//         }

//         return ans;
//     }
// };
