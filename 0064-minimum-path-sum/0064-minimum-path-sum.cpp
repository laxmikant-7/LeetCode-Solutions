class Solution {
public:
    // int solve(int i,int j,vector<vector<int>>& grid,int m,int n,vector<vector<int>> &dp){
    //     if(i<0 || i>=m || j<0 || j>=n) return INT_MAX;
    //     if(i==m-1 && j==n-1) return grid[i][j];

    //     if(dp[i][j]!=-1) return dp[i][j];

    //     int r=INT_MAX;
    //     int d=INT_MAX;

    //     int right=solve(i,j+1,grid,m,n,dp);
    //     int down=solve(i+1,j,grid,m,n,dp);

    //     if(right!=INT_MAX) r=grid[i][j]+right;
    //     if(down!=INT_MAX) d=grid[i][j]+down;

    //     return dp[i][j]=min(r,d);

    // }
    bool valid(int i,int j,int m,int n){
        if(i<0 || j<0 ||i>=m || j>=n) return false;
        return true;
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) dp[0][0]=grid[0][0];
                else{
                    int up=INT_MAX;
                    int left=INT_MAX;
                    if(valid(i-1,j,m,n)) up=dp[i-1][j];
                    if(valid(i,j-1,m,n)) left=dp[i][j-1];

                    dp[i][j]=grid[i][j]+min(up,left);
                }
            }
        }
        return dp[m-1][n-1];
    }
};