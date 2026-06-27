class Solution {
public:
    // int find(int i,int j,int m,int n,vector<vector<int>> &dp){
    //     if(i>=m || j>=n) return 0;
    //     if(i==m-1 && j==n-1) return 1;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int right=find(i,j+1,m,n,dp);
    //     int down=find(i+1,j,m,n,dp);
    //     return dp[i][j]=right+down;
    // }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));

        dp[m-1][n-1]=1;
        
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1) dp[i][j]=1;
                else{
                    int r=0;
                    int l=0;
                    if(j+1<n) r=dp[i][j+1];
                    if(i+1<m) l=dp[i+1][j];
                    dp[i][j]=r+l;
                }
            }
        }
        return dp[0][0];
    }
};