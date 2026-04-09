class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        for(int a=0;a<=amount;a++){
            dp[0][a]=(a%coins[0]==0)?1:0;
        }
        for(int i=1;i<n;i++){
            for(int a=0;a<=amount;a++){
                int nontake=dp[i-1][a];
                int take=0;
                if(coins[i]<=a) take=dp[i][a-coins[i]];
                dp[i][a]=take+nontake;
            }
        }
    return dp[n-1][amount];
    }
};