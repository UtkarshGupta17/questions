class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        for(int i=0;i<=n;i++){
            dp[i][0]=i;
        }
        for(int j=0;j<=m;j++){
            dp[0][j]=j;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]=1+min({dp[i-1][j-1],dp[i][j-1],dp[i-1][j]});
                }
            }

        }
        return dp[n][m];

        
    }
};




//memoization all test case passed

// class Solution {
// public:
// int func(int i,int j,string word1, string word2,vector<vector<int>> &dp){
//     if(i<0){
//         return j+1;
//     }
//     if(j<0){
//         return i+1;
//     }
//     if(dp[i][j]!=-1){
//         return dp[i][j];
//     }
//     if(word1[i]==word2[j]){
//         return 0+func(i-1,j-1,word1, word2,dp);
//     }

//     int insert=1+func(i,j-1,word1, word2,dp);
//     int replace=1+func(i-1,j-1,word1, word2,dp);
//     int del=1+func(i-1,j,word1, word2,dp);
//     int ans=min({insert,del,replace});
//     return dp[i][j]=ans;
// }
//     int minDistance(string word1, string word2) {
//         int n=word1.size();
//         int m=word2.size();
//         vector<vector<int>>dp(n,vector<int>(m,-1));
//         return func(n-1,m-1,word1,word2,dp);
//     }
// };





//Recursion Memory Limit Exceeded 25 / 1146 testcases passed

// class Solution {
// public:
// int func(int i,int j,string word1, string word2){
//     if(i<0){
//         return j+1;
//     }
//     if(j<0){
//         return i+1;
//     }

//     if(word1[i]==word2[j]){
//         return 0+func(i-1,j-1,word1, word2);
//     }

//     int insert=1+func(i,j-1,word1, word2);
//     int replace=1+func(i-1,j-1,word1, word2);
//     int del=1+func(i-1,j,word1, word2);
//     int ans=min({insert,del,replace});
//     return ans;
// }
//     int minDistance(string word1, string word2) {
//         int i=word1.size()-1;
//         int j=word2.size()-1;
//         return func(i,j,word1,word2);
//     }
// };