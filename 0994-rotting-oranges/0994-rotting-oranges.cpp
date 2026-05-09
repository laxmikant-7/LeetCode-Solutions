class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<int,int>> q;
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        int time=-1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    vis[i][j]=1;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int nx=x+dx[k];
                    int ny=y+dy[k];
                    if(nx>=0 && nx<m && ny>=0 && ny<n && !vis[nx][ny] && grid[nx][ny]==1){
                        grid[nx][ny]=2;
                        vis[nx][ny]=1;
                        q.push({nx,ny});
                    }
                }
            }
            time++;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return (time==-1)?0:time;
    }
};