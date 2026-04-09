class Solution {
public:
    int solve(int a,vector<int>& coins,int i,vector<vector<int>> &dp){
        if(a==0) return 1;
        if(i==coins.size()-1) return (a==coins[i])?1:0;
        if(dp[i][a]!=-1) return dp[i][a];
        int take=0;
        if(coins[i]<=a) take=solve(a-coins[i],coins,i,dp);
        int nontake=solve(a,coins,i+1,dp);
        return dp[i][a]=take+nontake;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return solve(amount,coins,0,dp);
    }
};