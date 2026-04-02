class Solution {
public:
    long long solve(int i, int j, int k, int m, int n,
                    vector<vector<int>>& coins,
                    vector<vector<vector<long long>>> &dp) {

        if (i >= m || j >= n) return LLONG_MIN;

        if (i == m-1 && j == n-1) {
            if (coins[i][j] < 0 && k < 2) return 0;
            return coins[i][j];
        }

        if (dp[i][j][k] != LLONG_MIN) return dp[i][j][k];

        long long ans = LLONG_MIN;
        long long right_same = solve(i, j+1, k, m, n, coins, dp);
        long long down_same  = solve(i+1, j, k, m, n, coins, dp);

        if (coins[i][j] >= 0) {
            if (right_same != LLONG_MIN)
                ans = max(ans, coins[i][j] + right_same);
            if (down_same != LLONG_MIN)
                ans = max(ans, coins[i][j] + down_same);
        } 
        else {
            if (right_same != LLONG_MIN)
                ans = max(ans, coins[i][j] + right_same);
            if (down_same != LLONG_MIN)
                ans = max(ans, coins[i][j] + down_same);
            if (k < 2) {
                long long right_skip = solve(i, j+1, k+1, m, n, coins, dp);
                long long down_skip  = solve(i+1, j, k+1, m, n, coins, dp);

                ans = max(ans, right_skip);
                ans = max(ans, down_skip);
            }
        }

        return dp[i][j][k] = ans;
    }

    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();

        vector<vector<vector<long long>>> dp(
            m, vector<vector<long long>>(n, vector<long long>(3, LLONG_MIN))
        );

        return (int)solve(0, 0, 0, m, n, coins, dp);
    }
};