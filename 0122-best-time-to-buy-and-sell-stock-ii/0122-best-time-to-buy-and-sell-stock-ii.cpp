class Solution {
public:
    // int solve(vector<int>& prices,int idx,int buy,vector<vector<int>> &dp){
    //     if(idx==prices.size()) return 0;
    //     if(dp[idx][buy]!=-1) return dp[idx][buy];
    //     int profit=0;
    //     if(buy){
    //         profit=max(-prices[idx]+solve(prices,idx+1,0,dp),solve(prices,idx+1,1,dp));
    //     }
    //     else{
    //         profit=max(prices[idx]+solve(prices,idx+1,1,dp),solve(prices,idx+1,0,dp));
    //     }
    //     return dp[idx][buy]=profit;
    // }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        dp[n][0]=dp[n][1]=0;
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                if(buy){
                    dp[i][buy]=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                }
                else{
                    dp[i][buy]=max(prices[i]+dp[i+1][1],dp[i+1][0]);
                }
            }
        }
        return dp[0][1];
    }
};