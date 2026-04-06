class Solution {
public:
    int solve(vector<int>& coins,int i,int amount,vector<vector<int>> &dp){
        if(amount==0) return 0;
        if(i==coins.size()) return INT_MAX;

        if(dp[i][amount]!=-1) return dp[i][amount];

        int take = INT_MAX;
        if (coins[i] <= amount) {
           int res = solve(coins, i, amount - coins[i], dp);
             if (res != INT_MAX) {
                 take = 1 + res;
              }
}

        int nontake=0+solve(coins,i+1,amount,dp);

        return dp[i][amount]=min(take,nontake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int count=0;
        int i=0;
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans=solve(coins,i,amount,dp);
        return (ans==INT_MAX)?-1:ans;
    }
};