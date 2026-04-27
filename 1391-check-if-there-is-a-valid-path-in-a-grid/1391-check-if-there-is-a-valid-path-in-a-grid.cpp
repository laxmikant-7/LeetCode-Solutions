class Solution {
public:
    char findmove(int i,int j,int nx,int ny){
    if(nx == i && ny == j+1) return 'R';
    if(nx == i && ny == j-1) return 'L';
    if(nx == i-1 && ny == j) return 'U';
    return 'D';
}
    bool isconnect(char move,int i,int j,vector<vector<int>>& grid){
        if(move=='R'){
            if(grid[i][j]==1 || grid[i][j]==3 || grid[i][j]==5) return true;
            return false;
        }
        else if(move=='L'){
            if(grid[i][j]==1 || grid[i][j]==4 || grid[i][j]==6) return true;
            return false;
        }
        else if(move=='U'){
            if(grid[i][j]==2 || grid[i][j]==3 || grid[i][j]==4) return true;
            return false;
        }
        else{
            if(grid[i][j]==2 || grid[i][j]==6 || grid[i][j]==5) return true;
        }
        return false;
    }

    bool solve(vector<vector<int>>& grid,unordered_map<int,vector<int>> &mp,vector<vector<int>> &vis,int i,int j,int n,int m){
      
        if(i<0 || i>=n || j<0 || j>=m) return false;
        if(vis[i][j]) return false;
        if(i==n-1 && j==m-1) return true;
        vis[i][j]=1;
        auto vec=mp[grid[i][j]];
        int nx1=i+vec[0];
        int ny1=j+vec[1];
        int nx2=i+vec[2];
        int ny2=j+vec[3];
        bool m1 = false, m2 = false;
        char move1=findmove(i,j,nx1,ny1);
        char move2=findmove(i,j,nx2,ny2);

if(nx1>=0 && nx1<n && ny1>=0 && ny1<m){
    if(isconnect(move1,nx1,ny1,grid)){
        m1 = solve(grid,mp,vis,nx1,ny1,n,m);
    }
}

if(nx2>=0 && nx2<n && ny2>=0 && ny2<m){
    if(isconnect(move2,nx2,ny2,grid)){
        m2 = solve(grid,mp,vis,nx2,ny2,n,m);
    }
}
        
        vis[i][j]=0;
        return (m1 || m2);
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        unordered_map<int,vector<int>> mp;
        mp[1]={0,-1,0,1};
        mp[2]={-1,0,1,0};
        mp[3]={0,-1,1,0};
        mp[4]={0,1,1,0};
        mp[5]={0,-1,-1,0};
        mp[6]={0,1,-1,0};
        vector<vector<int>> vis(n,vector<int>(m,0));
        return solve(grid,mp,vis,0,0,n,m);
    }
};