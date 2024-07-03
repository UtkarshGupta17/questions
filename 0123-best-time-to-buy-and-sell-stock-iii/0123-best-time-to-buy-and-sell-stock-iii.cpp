class Solution {
public:
int func(int ind,int buy,vector<int>& prices,vector<vector<vector<int>>> &dp,int cap){
    if(ind==prices.size()){
        return 0;
    }
    if(cap==0){
        return 0;
    }

    if (dp[ind][buy][cap]!= -1) {
            return dp[ind][buy][cap];
    }
    int profit=INT_MIN;
    if(buy){
        profit=max(func(ind+1,0,prices,dp,cap)-prices[ind],func(ind+1,1,prices,dp,cap));
    }
    else{
        profit=max(func(ind+1,0,prices,dp,cap),func(ind+1,1,prices,dp,cap-1)+prices[ind]);
    }
    return dp[ind][buy][cap]=profit;

}

    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(3, -1)));
        return func(0,1,prices,dp,2);
        
    }
};

