class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int low=x;
        int high=low+k-1;
        while(low<high){
            for(int j=y;j<k+y;j++){
                int temp=grid[low][j];
                grid[low][j]=grid[high][j];
                grid[high][j]=temp;
            }
            low++;
            high--;
        }
        return grid;
    }
};