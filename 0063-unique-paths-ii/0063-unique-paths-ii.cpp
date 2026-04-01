class Solution {
public:
    int find(int i,int j,int m,int n,vector<vector<int>> &grid,vector<vector<int>> &dp){
        if(i>=m || j>=n || grid[i][j]==1) return 0;
        if(i==m-1 && j==n-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int right=find(i,j+1,m,n,grid,dp);
        int down=find(i+1,j,m,n,grid,dp);
        return dp[i][j]=right+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(grid[0][0]==1 || grid[m-1][n-1]==1) return 0;
        int i=0,j=0;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return find(i,j,m,n,grid,dp);
    }
};