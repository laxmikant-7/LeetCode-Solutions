class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int n=h.size();
        int m=h[0].size();
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        vector<vector<int>> effort(n,vector<int>(m,INT_MAX));
        effort[0][0]=0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0,0,0});
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int eff=it[0];
            int x=it[1];
            int y=it[2];
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m){
                    int neff=max(eff,abs(h[x][y]-h[nx][ny]));
                    if(neff<effort[nx][ny]){
                    effort[nx][ny]=neff;
                    pq.push({neff,nx,ny});
                    }
                }
            }
        }

        return effort[n-1][m-1];
    }
};