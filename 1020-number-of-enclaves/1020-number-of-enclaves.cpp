class Solution {
public:
    void dfs(int i,int j,vector<vector<int>> &grid,vector<vector<int>>&vis){
        vis[i][j]=1;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        int n=grid.size();
        int m=grid[0].size();
        for(int k=0;k<4;k++){
            int nrow=i+drow[k];
            int ncol=j+dcol[k];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                dfs(nrow,ncol,grid,vis);
            }
        }
        return;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        //1st row & lat row
        for(int j=0;j<m;j++){
            if(grid[0][j]==1 && !vis[0][j]){
                dfs(0,j,grid,vis);
            }
            if(grid[n-1][j]==1 && !vis[n-1][j]){
                dfs(n-1,j,grid,vis);
            }
        }
        //1st col and last col
        for(int i=0;i<n;i++){
            if(grid[i][0]==1 && !vis[i][0]){
                dfs(i,0,grid,vis);
            }
            if(grid[i][m-1]==1 && !vis[i][m-1]){
                dfs(i,m-1,grid,vis);
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]) count++;
            }
        }
        return count;
    }
};