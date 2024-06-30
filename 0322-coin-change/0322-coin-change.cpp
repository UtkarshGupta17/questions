class Solution {
public:
    int func(vector<int>& coins, int ind, int target, vector<vector<int>>& dp) {
        if (target == 0) {
            return 0;
        }
        if (ind < 0 || target < 0) {
            return INT_MAX; 
        }

        if (dp[ind][target] != -1) {
            return dp[ind][target];
        }

        int nottake = func(coins, ind - 1, target, dp);

        int take = INT_MAX;
        if (coins[ind] <= target) {
            int res = func(coins, ind, target - coins[ind], dp);
            if (res != INT_MAX) {
                take = 1 + res;
            }
        }

        return dp[ind][target] = min(take, nottake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int result = func(coins, n - 1, amount, dp);
        return result == INT_MAX ? -1 : result;
    }
};
