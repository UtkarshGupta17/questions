class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;//amount=0 hence one way
        }


        for (int j = 0; j <= amount; j++) {
            if (j % coins[0] == 0) {
                dp[0][j] = 1;//if index comes to the last index and it is multiple of amount(j) then add 1
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= amount; j++) {//starting form j=1 as amount can not be one and is still it is the initially we have done for that
                int nottake = dp[i-1][j];
                int take = 0;
                if (j >= coins[i]) {
                    take = dp[i][j - coins[i]]; 
                }
                dp[i][j] = take + nottake;
            }
        }
        return dp[n-1][amount];
    }
};


// class Solution {
// public:
// int func(vector<int>& coins,int ind,int target,vector<vector<int>> &dp){
//     if(ind==0){
//         return (target%coins[ind]==0);
//     }

//     if(dp[ind][target]!=-1){
//         return dp[ind][target];
//     }
//     int nottake=func(coins,ind-1,target,dp);
//     int take=0;
//     if(coins[ind]<=target){
//         take=func(coins,ind,target-coins[ind],dp);
//     }

//     return dp[ind][target]=take+nottake;
// }
//     int change(int amount, vector<int>& coins) {
//         int n=coins.size();
//         vector<vector<int>> dp(n,vector<int>(amount+1,-1));
//         return func(coins,n-1,amount,dp);
        
//     }
// };