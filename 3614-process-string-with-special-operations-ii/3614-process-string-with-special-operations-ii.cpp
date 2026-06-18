class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();
        vector<long long> len(n + 1, 0);
        for (int i = 0; i < n; i++) {
            len[i + 1] = len[i];

            if (islower(s[i])) {
                len[i + 1]++;
            }
            else if (s[i] == '*') {
                if (len[i + 1] > 0)
                    len[i + 1]--;
            }
            else if (s[i] == '#') {
                len[i + 1] *= 2;
            }
        }
        if (k >= len[n])
            return '.';

        for (int i = n - 1; i >= 0; i--) {
            long long curLen = len[i + 1];
            long long prevLen = len[i];

            if (islower(s[i])) {
                if (k == prevLen)
                    return s[i];
            }
            else if (s[i] == '*') {
            }
            else if (s[i] == '#') {

                long long half = prevLen;

                if (k >= half)
                    k -= half;

            }
            else if (s[i] == '%') {

                k = curLen - 1 - k;
            }
        }
        return '.';
    }
};