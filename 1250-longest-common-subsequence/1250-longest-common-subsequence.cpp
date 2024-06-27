//Memoization 45 / 47 testcases passed Time Limit Exceeded

// class Solution {
// public:
// int func(int ind1,int ind2,string text1, string text2,vector<vector<int>> &dp){
//     if(ind1<0||ind2<0){
//         return 0;
//     }
//     int take=0;
//     if(dp[ind1][ind2]!=-1){
//         return dp[ind1][ind2];
//     }
//     if(text1[ind1]==text2[ind2]){
//         take=1+func(ind1-1,ind2-1,text1,text2,dp);
//     }
//     int nottake=0+max(func(ind1-1,ind2,text1,text2,dp),func(ind1,ind2-1,text1,text2,dp));
//     dp[ind1][ind2]=max(take,nottake);

//     return dp[ind1][ind2];
// }
//     int longestCommonSubsequence(string text1, string text2) {
//         int n=text1.size();
//         int m=text2.size();
//         vector<vector<int>> dp(n,vector<int>(m,-1));
//         int ind1=text1.size()-1;
//         int ind2=text2.size()-1;
//         return func(ind1,ind2,text1,text2,dp);
        
//     }
// };

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return dp[n][m];
    }
};
