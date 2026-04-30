class Solution {
public:
int solve(int i, int j, vector<vector<int>>& grid, vector<int>& costs, int k, int cc,
          vector<vector<vector<int>>>& dp) {
    
    if(i == grid.size()-1 && j == grid[0].size()-1) 
        return grid[i][j];

    if(dp[i][j][cc] != -1) 
        return dp[i][j][cc];

    int r = INT_MIN;
    int ny1 = j + 1;

    if(ny1 < grid[0].size() && cc + costs[grid[i][ny1]] <= k) {
        int temp = solve(i, ny1, grid, costs, k,
                         cc + costs[grid[i][ny1]], dp);
        if(temp != INT_MIN)
            r = grid[i][j] + temp;
    }

    int d = INT_MIN;
    int nx2 = i + 1;

    if(nx2 < grid.size() && cc + costs[grid[nx2][j]] <= k) {
        int temp = solve(nx2, j, grid, costs, k,
                         cc + costs[grid[nx2][j]], dp);
        if(temp != INT_MIN)
            d = grid[i][j] + temp;
    }

    return dp[i][j][cc] = max(d, r);
}
int maxPathScore(vector<vector<int>>& grid, int k) {
    int m = grid.size();
    int n = grid[0].size();

    vector<int> costs = {0,1,1};

    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k+1, -1)));

    int ans = solve(0, 0, grid, costs, k, 0, dp);

    return (ans == INT_MIN) ? -1 : ans;
}
};