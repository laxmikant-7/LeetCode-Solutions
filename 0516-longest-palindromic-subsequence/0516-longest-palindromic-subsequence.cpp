class Solution {
public:
    // int solve(string &s,int i,int j,vector<vector<int>> &dp){
    //     if(i==j) return 1;
    //     if(i>j) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int length=0;
    //     if(s[i]==s[j]){
    //         length=2+solve(s,i+1,j-1,dp);
    //     }
    //     else{
    //         length=max(solve(s,i+1,j,dp),solve(s,i,j-1,dp));
    //     }
    //     return dp[i][j]=length;
    // }
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        //return solve(s,0,n-1,dp);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){
                    dp[i][j]=1;
                }
                else if(i>j) dp[i][j]=0;
            }
        }

        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(s[i]==s[j]){
                    dp[i][j]=2+dp[i+1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];

    }
};