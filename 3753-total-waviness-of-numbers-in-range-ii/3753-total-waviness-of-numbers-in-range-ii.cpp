class Solution {
public:
    struct Node {
        long long cnt;
        long long wav;
    };
    string s;
    Node dp[20][17][11][11][2];
    bool vis[20][17][11][11][2];
    Node dfs(int pos, int len, int prev2, int prev1,
             bool started, bool tight) {
        if (pos == s.size()) {
            return {1, 0};
        }
        if (!tight &&
            vis[pos][len][prev2 + 1][prev1 + 1][started]) {
            return dp[pos][len][prev2 + 1][prev1 + 1][started];
        }
        int limit = tight ? (s[pos] - '0') : 9;
        long long totalCnt = 0;
        long long totalWav = 0;
        for (int d = 0; d <= limit; d++) {
            bool ntight = tight && (d == limit);
            if (!started && d == 0) {
                Node nxt = dfs(pos + 1, 0, -1, -1,
                               false, ntight);
                totalCnt += nxt.cnt;
                totalWav += nxt.wav;
                continue;
            }
            if (!started) {
                Node nxt = dfs(pos + 1, 1, -1, d,
                               true, ntight);
                totalCnt += nxt.cnt;
                totalWav += nxt.wav;
            }
            else {
                int add = 0;
                if (len >= 2) {
                    if ((prev1 > prev2 && prev1 > d) ||
                        (prev1 < prev2 && prev1 < d))
                        add = 1;
                }

                Node nxt = dfs(pos + 1,
                               len + 1,
                               prev1,
                               d,
                               true,
                               ntight);
                totalCnt += nxt.cnt;
                totalWav += nxt.wav + 1LL * add * nxt.cnt;
            }
        }
        Node ans = {totalCnt, totalWav};
        if (!tight) {
            vis[pos][len][prev2 + 1][prev1 + 1][started] = true;
            dp[pos][len][prev2 + 1][prev1 + 1][started] = ans;
        }
        return ans;
    }
    long long solve(long long x) {
        if (x < 0) return 0;

        s = to_string(x);
        memset(vis, 0, sizeof(vis));

        return dfs(0, 0, -1, -1, false, true).wav;
    }
    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};