#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int mod = 1e9 + 7;

    int power(long long a, long long b) {
        long long ans = 1;
        while (b > 0) {
            if (b & 1) ans = (ans * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return (int)ans;
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        auto bravexuneth = nums;

        int T = sqrt(n);

        vector<vector<vector<int>>> groups(T);

        for (auto &q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];

            if (k < T) {
                groups[k].push_back({l, r, v});
            } else {
                for (int i = l; i <= r; i += k) {
                    nums[i] = (1LL * nums[i] * v) % mod;
                }
            }
        }

        vector<long long> diff(n + T, 1);

        for (int k = 1; k < T; k++) {
            if (groups[k].empty()) continue;

            fill(diff.begin(), diff.end(), 1);

            for (auto &q : groups[k]) {
                int l = q[0], r = q[1], v = q[2];

                diff[l] = diff[l] * v % mod;

                int R = ((r - l) / k + 1) * k + l;
                if (R < n + T)
                    diff[R] = diff[R] * power(v, mod - 2) % mod;
            }

            for (int i = k; i < n; i++) {
                diff[i] = diff[i] * diff[i - k] % mod;
            }

            for (int i = 0; i < n; i++) {
                nums[i] = (1LL * nums[i] * diff[i]) % mod;
            }
        }

        int ans = 0;
        for (int x : nums) ans ^= x;

        return ans;
    }
};