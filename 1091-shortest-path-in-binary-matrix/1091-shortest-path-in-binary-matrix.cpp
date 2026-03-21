class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(n==1 && grid[0][0]==0) return 1;
        if(grid[0][0]==1) return -1;
        if(grid[n-1][n-1]==1) return -1;
        int dx[]={-1,-1,0,1,1,1,0,-1};
        int dy[]={0,1,1,1,0,-1,-1,-1};
        vector<vector<int>> vis(n,vector<int>(n,INT_MAX));
     
        queue<pair<int,pair<int,int>>> q;
        q.push({1,{0,0}});
        while(!q.empty()){
            int currdist=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            q.pop();
            for(int k=0;k<8;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx>=0 && nx<n && ny>=0 && ny<n){
                    if(grid[nx][ny]==1){
                        continue;
                    }
                    else{
                    if(vis[nx][ny]>currdist+1){
                        vis[nx][ny]=currdist+1;
                        q.push({currdist+1,{nx,ny}});
                    }
                }
                }
            }
        }
        return (vis[n-1][n-1]==INT_MAX)?-1:vis[n-1][n-1];
    }
};