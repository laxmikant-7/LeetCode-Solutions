class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& grid,vector<vector<int>>& vis){
        vis[i][j]=1;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        int n=grid.size();
        int m=grid[0].size();
        for(int k=0;k<4;k++){
            int nrow=i+drow[k];
            int ncol=j+dcol[k];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]=='1'){
                dfs(nrow,ncol,grid,vis);
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    count++;
                    dfs(i,j,grid,vis);
                }
            }
        }
        return count;
    }
};