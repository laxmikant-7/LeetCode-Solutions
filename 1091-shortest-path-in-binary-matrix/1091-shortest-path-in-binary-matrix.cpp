class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        int dx[] = {-1, -1, -1,  0, 0,  1, 1, 1};
        int dy[] = {-1,  0,  1, -1, 1, -1, 0, 1};
        set<pair<int,pair<int,int>>> st;
        dist[0][0]=1;
        grid[0][0]=1;
        st.insert({1,{0,0}});

        while(!st.empty()){
            auto it=*(st.begin());
            int dis=it.first;
            int x=it.second.first;
            int y=it.second.second;
            st.erase(it);
            if(x==n-1 && y==n-1) return dis;
            for(int i=0;i<8;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                int ndis=dist[x][y]+1;
                if(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny]==0){
                    if(dist[nx][ny]>ndis){
                        dist[nx][ny]=ndis;
                        st.insert({ndis,{nx,ny}});
                    }
                }
            }  
        }
        if(dist[n-1][n-1]==INT_MAX) return -1;
        return dist[n-1][n-1];
    }
};