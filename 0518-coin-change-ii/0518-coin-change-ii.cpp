class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<long long>> dp(n,vector<long long>(amount+1,0));
        for(int a=0;a<=amount;a++){
            dp[0][a]=(a%coins[0]==0)?1:0;
        }
        for(int i=0;i<n;i++) dp[i][0]=1;
        for(long long i=1;i<n;i++){
            for(long long a=0;a<=amount;a++){
                long long nontake=dp[i-1][a];
                long long take=0;
                if(coins[i]<=a) take=dp[i][a-coins[i]];
                dp[i][a] = min(take + nontake, (long long)INT_MAX);
            }
        }
    return (int)dp[n-1][amount];
    }
};