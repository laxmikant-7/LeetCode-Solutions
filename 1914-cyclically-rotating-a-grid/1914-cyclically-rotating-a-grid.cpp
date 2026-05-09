class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int layers = min(m, n) / 2;
        for (int layer = 0; layer < layers; layer++) {
            vector<int> temp;
            int top = layer;
            int left = layer;
            int bottom = m - layer - 1;
            int right = n - layer - 1;
            // left column
            for (int i = top; i <= bottom; i++) {
                temp.push_back(grid[i][left]);
            }
            // bottom row
            for (int j = left + 1; j <= right; j++) {
                temp.push_back(grid[bottom][j]);
            }
            // right column
            for (int i = bottom - 1; i >= top; i--) {
                temp.push_back(grid[i][right]);
            }
            // top row
            for (int j = right - 1; j > left; j--) {
                temp.push_back(grid[top][j]);
            }
            int sz = temp.size();
            int rot = k % sz;
            vector<int> rotated(sz);
            for (int i = 0; i < sz; i++) {
                rotated[i] = temp[(i + sz - rot) % sz];
            }
            int idx = 0;
            // left column
            for (int i = top; i <= bottom; i++) {
                grid[i][left] = rotated[idx++];
            }
            // bottom row
            for (int j = left + 1; j <= right; j++) {
                grid[bottom][j] = rotated[idx++];
            }
            // right column
            for (int i = bottom - 1; i >= top; i--) {
                grid[i][right] = rotated[idx++];
            }
            // top row
            for (int j = right - 1; j > left; j--) {
                grid[top][j] = rotated[idx++];
            }
        }
        return grid;
    }
};