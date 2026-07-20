class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int> temp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                temp.push_back(grid[i][j]);
            }
        }
        k=(k%(n*m));
        int stidx=(n*m)-k;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                grid[i][j]=temp[stidx % (n*m)];
                stidx++;
            }
        }
        return grid;
    }
};