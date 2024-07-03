class Solution {
public:
int func(int ind,int buy,vector<int>& prices,vector<vector<int>> &dp){
    if(ind==prices.size()){
        return 0;
    }
    if(dp[ind][buy]!=-1){
        return dp[ind][buy];
    }
    int profit=INT_MIN;
    if(buy){
        profit=max(func(ind+1,0,prices,dp)-prices[ind],func(ind+1,1,prices,dp));
    }
    else{
        profit=max(func(ind+1,0,prices,dp),func(ind+1,1,prices,dp)+prices[ind]);
    }
    return dp[ind][buy]=profit;

}
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return func(0,1,prices,dp);
        
    }
};