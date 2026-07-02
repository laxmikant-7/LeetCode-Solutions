class Solution {
public:
    bool solve(int i,int j,vector<vector<int>>& grid, int health,vector<vector<int>> &vis,vector<vector<vector<int>>> &dp){
        int m=grid.size();
        int n=grid[0].size();
        if(i==m-1 && j==n-1){
            if(grid[i][j]==1) health--;
            return (health>=1);
        }
        if(health<=0) return false;

        vis[i][j]=1;
        if(grid[i][j]==1) health--;
        if(dp[i][j][health]!=-1){
            return (dp[i][j][health])?true:false;
        }
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};

        for(int k=0;k<4;k++){
            int nx=i+dx[k];
            int ny=j+dy[k];
            if(nx>=0 && nx<m && ny>=0 && ny<n && !vis[nx][ny]){
                if(solve(nx,ny,grid,health,vis,dp)) return true;
                vis[nx][ny]=0;
            }
        }
        vis[i][j]=0;
        dp[i][j][health]=0;
        return false;
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(m+n+1,-1)));
        return solve(0,0,grid,health,vis,dp);
    }
};