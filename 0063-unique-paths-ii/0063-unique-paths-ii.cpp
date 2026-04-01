class Solution {
public:
    // int find(int i,int j,int m,int n,vector<vector<int>> &grid,vector<vector<int>> &dp){
    //     if(i>=m || j>=n || grid[i][j]==1) return 0;
    //     if(i==m-1 && j==n-1) return 1;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int right=find(i,j+1,m,n,grid,dp);
    //     int down=find(i+1,j,m,n,grid,dp);
    //     return dp[i][j]=right+down;
    // }

    bool valid(int i,int j,int m,int n){
        if(i<0 || i>=m || j<0 || j>=n) return false;
        return true;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(grid[0][0]==1 || grid[m-1][n-1]==1) return 0;
        int i=0,j=0;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) dp[i][j]=1;
                else if(grid[i][j]==1) dp[i][j]=0;
                else{
                    int up=(valid(i-1,j,m,n))?dp[i-1][j]:0;
                    int left=(valid(i,j-1,m,n))?dp[i][j-1]:0;
                    dp[i][j]=up+left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};