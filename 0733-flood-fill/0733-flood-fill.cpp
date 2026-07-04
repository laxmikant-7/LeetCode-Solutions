class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& i, int sr, int sc, int c) {
        int m=i.size();
        int n=i[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        vis[sr][sc]=true;
        queue<pair<pair<int,int>,int>> q;
        q.push({{sr,sc},i[sr][sc]});
        i[sr][sc]=c;
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        while(!q.empty()){
            int x=q.front().first.first;
            int y=q.front().first.second;
            int val=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx>=0 && nx<m && ny>=0 && ny<n && !vis[nx][ny] && i[nx][ny]==val){
                    q.push({{nx,ny},val});
                    i[nx][ny]=c;
                    vis[nx][ny]=true;
                }
            }

        }
        return i;
    }
};