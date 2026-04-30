class Solution {
public:
    // int solve(string &s1, string &s2,int i,int j,vector<vector<int>> &dp){
    //     if(i==0 || j==0){
    //         return 0;
    //     }
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int maxl=0;
    //     if(s1[i-1]==s2[j-1]){
    //         maxl=1+solve(s1,s2,i-1,j-1,dp);
    //     }
    //     else{
    //         maxl=max(solve(s1,s2,i-1,j,dp),solve(s1,s2,i,j-1,dp));
    //     }
    //     return dp[i][j]=maxl;
    // }
    int minDistance(string word1, string word2) {
        int n1=word1.size();
        int n2=word2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        //int maxlength=solve(word1,word2,n1,n2,dp);
        //return (n1-maxlength)+(n2-maxlength);


        for(int i=0;i<=n1;i++){
            for(int j=0;j<=n2;j++){
                if(i==0 || j==0) dp[i][j]=0;
            }
        }


        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
    int maxi=dp[n1][n2];
    return (n1-maxi)+(n2-maxi);
    }
};