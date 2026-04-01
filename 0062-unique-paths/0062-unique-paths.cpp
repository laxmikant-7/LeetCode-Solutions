class Solution {
public:
    int find(int m,int n,int i,int j,vector<vector<int>> &dp){
        if(i>=m || j>=n) return 0;
        if(i==m-1 && j==n-1) return 1;

        if(dp[i][j]!=-1) return dp[i][j];

        int r=find(m,n,i,j+1,dp);
        int l=find(m,n,i+1,j,dp);

        return dp[i][j]=r+l;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        int i=0;
        int j=0;
        return find(m,n,i,j,dp);
    }
};