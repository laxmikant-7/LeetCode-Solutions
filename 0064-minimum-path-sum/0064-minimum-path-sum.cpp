class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& grid,int m,int n,vector<vector<int>> &dp){
        if(i<0 || i>=m || j<0 || j>=n) return INT_MAX;
        if(i==m-1 && j==n-1) return grid[i][j];

        if(dp[i][j]!=-1) return dp[i][j];

        int r=INT_MAX;
        int d=INT_MAX;

        int right=solve(i,j+1,grid,m,n,dp);
        int down=solve(i+1,j,grid,m,n,dp);

        if(right!=INT_MAX) r=grid[i][j]+right;
        if(down!=INT_MAX) d=grid[i][j]+down;

        return dp[i][j]=min(r,d);

    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(0,0,grid,m,n,dp);
    }
};