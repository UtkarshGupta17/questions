//tabulation (bottom-up)
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; i++) {
            dp[i][0] = 1;
        }
        for (int j = 0; j < n; j++) {
            dp[0][j] = 1;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};


//memoization (top-down)
// class Solution {
// public:
// int func(int i,int j,vector<vector<int>> &dp){
//     if(i==0 && j==0){
//         return 1;
//     }
//     if(i<0||j<0){
//         return 0;
//     }
//     if(dp[i][j]!=-1){
//         return dp[i][j];
//     }
//     int up=func(i-1,j,dp);
//     int left=func(i,j-1,dp);

//     return dp[i][j]=up+left;
// }
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m,vector<int>(n,-1));
//         return func(m-1,n-1,dp);
        
//     }
// };



//Reccursive solution Time Limit Exceeded
//40 / 63 testcases passed

// class Solution {
// public:
// int func(int i,int j){
//     if(i==0 && j==0){
//         return 1;
//     }
//     if(i<0||j<0){
//         return 0;
//     }
//     int up=func(i-1,j);
//     int left=func(i,j-1);

//     return up+left;
// }
//     int uniquePaths(int m, int n) {
//         return func(m-1,n-1);
        
//     }
// };

