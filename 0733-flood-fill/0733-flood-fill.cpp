class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& i, int sr, int sc, int c) {
        int m=i.size();
        int n=i[0].size();
        vector<vector<int>> temp=i;
        temp[sr][sc]=c;
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        vis[sr][sc]=true;
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            int val=i[x][y];
            q.pop();
         
            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx>=0 && nx<m && ny>=0 && ny<n && !vis[nx][ny] && i[nx][ny]==val){
                    temp[nx][ny]=c;
                    vis[nx][ny]=true;
                    q.push({nx,ny});
                }
            }

        }
        return temp;
    }
};