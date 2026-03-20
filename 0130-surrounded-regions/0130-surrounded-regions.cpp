class Solution {
public:
    void solve(vector<vector<char>>& b) {
        int n=b.size();
        int m=b[0].size();
        vector<vector<int>> vis(n,vector<int>(m,1));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(b[i][j]=='O'){
                    vis[i][j]=0;
                    b[i][j]='X';
                    if(i==0 || i==n-1 || j==0 || j==m-1){
                        q.push({i,j});
                    }
                }
            }
        }
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            vis[r][c]=1;
            b[r][c]='O';
            for(int k=0;k<4;k++){
                int nrow=r+drow[k];
                int ncol=c+dcol[k];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0){
                    q.push({nrow,ncol});
                }
            }
        }
        return;
    }
};