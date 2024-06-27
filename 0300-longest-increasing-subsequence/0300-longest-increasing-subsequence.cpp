//memoization(T.C = 2^n) ----time limit exceeded 22/55 test cases

// class Solution {
// public:
// int func(int ind,int prev,vector<int>& nums,int n,vector<vector<int>> &dp){
//     if(ind==n){
//         return 0;
//     }
//     int nottake=0+func(ind+1,prev,nums,n,dp);
//     if(dp[ind][prev+1]!=-1){
//         return dp[ind][prev+1];
//     }
//     int take=0;
//     if(prev==-1||nums[ind]>nums[prev]){
//         take=1+func(ind+1,ind,nums,n,dp);
//     }
//     dp[ind][prev+1]=max(take,nottake);
//     return dp[ind][prev+1];
    
// }
//     int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         vector<vector<int>> dp(n,vector<int>(n+1,-1));
//         int ans=func(0,-1,nums,n,dp);
//         return ans;
        
//     }
// };

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        vector<int> dp(n, 1);
        int maxLength = 1;
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    //Update the index where dp[j] is storing the 
                    //length of subseq till the most extended element 
                    //in the array and then it will get updated.
                    //to the longest value either dp[i] or dp[j]+1 if length is increased 
                }
            }
            maxLength = max(maxLength, dp[i]);
        }
        
        return maxLength;
    }
};