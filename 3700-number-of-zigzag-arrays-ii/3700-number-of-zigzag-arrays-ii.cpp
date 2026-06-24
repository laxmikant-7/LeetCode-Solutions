class Solution {
public:
    static const int MOD = 1e9 + 7;
    using ll = long long;
    using Mat = vector<vector<ll>>;

    Mat mul(const Mat& A, const Mat& B) {
        int n = A.size();
        Mat C(n, vector<ll>(n));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (!A[i][k]) continue;
                ll x = A[i][k];
                for (int j = 0; j < n; j++) {
                    if (!B[k][j]) continue;
                    C[i][j] = (C[i][j] + x * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    vector<ll> mulVec(const Mat& A, const vector<ll>& v) {
        int n = A.size();
        vector<ll> res(n);

        for (int i = 0; i < n; i++) {
            ll cur = 0;
            for (int j = 0; j < n; j++) {
                if (!A[i][j]) continue;
                cur = (cur + A[i][j] * v[j]) % MOD;
            }
            res[i] = cur;
        }
        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        int sz = 2 * m;

        auto id = [&](int v, int d) {
            return v * 2 + d;
        };

        if (n == 1) return m;

        vector<ll> dp(sz);

        for (int a = 0; a < m; a++) {
            for (int b = 0; b < m; b++) {
                if (a < b) dp[id(b, 0)]++;
                else if (a > b) dp[id(b, 1)]++;
            }
        }

        if (n == 2) {
            ll ans = 0;
            for (ll x : dp) ans = (ans + x) % MOD;
            return ans;
        }

        Mat T(sz, vector<ll>(sz));

        for (int v = 0; v < m; v++) {
            for (int nv = 0; nv < v; nv++)
                T[id(nv, 1)][id(v, 0)] = 1;

            for (int nv = v + 1; nv < m; nv++)
                T[id(nv, 0)][id(v, 1)] = 1;
        }

        long long p = n - 2;

        while (p) {
            if (p & 1) dp = mulVec(T, dp);
            T = mul(T, T);
            p >>= 1;
        }

        ll ans = 0;
        for (ll x : dp) ans = (ans + x) % MOD;

        return ans;
    }
};