class Solution {
public:
    int solve(int i,int buy,vector<int> &p,vector<vector<int>> &dp){
        if(i>=p.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        int profit=0;
        if(buy){
            profit=max(-p[i]+solve(i+1,0,p,dp),solve(i+1,1,p,dp));
        }
        else{
            profit=max(p[i]+solve(i+1,1,p,dp),solve(i+1,0,p,dp));
        }
        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0,1,prices,dp);
    }
};