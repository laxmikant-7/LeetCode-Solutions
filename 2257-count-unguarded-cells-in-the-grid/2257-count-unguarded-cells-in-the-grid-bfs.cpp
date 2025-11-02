class Solution {
public:

    void markGarded(vector<vector<int>> &grid,int row,int col){
        //UP
        for(int i=row-1;i>=0;i--){
            if(grid[i][col]==1 || grid[i][col]==2){
                break;
            }
            grid[i][col]=3;
        }
        //DOWN
        for(int i=row+1;i<grid.size();i++){
            if(grid[i][col]==1 || grid[i][col]==2){
                break;
            }
            grid[i][col]=3;
        }
        //left
        for(int j=col-1;j>=0;j--){
            if(grid[row][j]==1 || grid[row][j]==2){
                break;
            }
            grid[row][j]=3;
        }
        //right
        for(int j=col+1;j<grid[0].size();j++){
            if(grid[row][j]==1 || grid[row][j]==2){
                break;
            }
            grid[row][j]=3;
        }
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m,vector<int>(n,0));
        for(auto vec:guards){
            int i=vec[0];
            int j=vec[1];
            grid[i][j]=1;//gaurds cells
        }
        for(vector<int> &vec:walls){
            int i=vec[0];
            int j=vec[1];
            grid[i][j]=2;//walls cells
        }
        for(vector<int> &gaurd:guards){
            int i=gaurd[0];
            int j=gaurd[1];
            markGarded(grid,i,j);
        }
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) count++;
            }
        }
        return count;
    }
};