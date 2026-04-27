class Solution {
public:
    // int solve(string &s,int i,int j){
    //     if(i>=j) return 0;
    //     if(s[i]==s[j]){
    //         return solve(s,i+1,j-1);
    //     }
    //     return 1+min(solve(s,i+1,j),solve(s,i,j-1));
    // }
    int minInsertions(string s) {
        int n1=s.size();
        vector<vector<int>> dp(n1,vector<int>(n1,-1));
        for(int i=0;i<n1;i++){
            for(int j=0;j<n1;j++){
                if(i>=j) dp[i][j]=0;
            }
        }
        for(int i=n1-1;i>=0;i--){
            for(int j=i+1;j<n1;j++){
                if(s[i]==s[j]){
                    dp[i][j]=dp[i+1][j-1];
                }
                else{
                    dp[i][j]=1+min(dp[i][j-1],dp[i+1][j]);
                }
            }
        }
        return dp[0][n1-1];
    }
};