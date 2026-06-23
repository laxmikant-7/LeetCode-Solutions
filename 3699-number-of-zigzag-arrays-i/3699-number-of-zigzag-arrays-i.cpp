class Solution {
public:
    static const int MOD = 1e9 + 7;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        vector<long long> up(m + 2, 0), down(m + 2, 0);

        for (int i = 1; i <= m; i++) {
            up[i] = i - 1;
            down[i] = m - i;
        }

        for (int len = 3; len <= n; len++) {
            vector<long long> newUp(m + 2, 0), newDown(m + 2, 0);

            long long pref = 0;
            for (int i = 1; i <= m; i++) {
                newUp[i] = pref;
                pref = (pref + down[i]) % MOD;
            }

            long long suff = 0;
            for (int i = m; i >= 1; i--) {
                newDown[i] = suff;
                suff = (suff + up[i]) % MOD;
            }

            up.swap(newUp);
            down.swap(newDown);
        }

        long long ans = 0;
        for (int i = 1; i <= m; i++) {
            ans = (ans + up[i] + down[i]) % MOD;
        }

        return ans;
    }
};