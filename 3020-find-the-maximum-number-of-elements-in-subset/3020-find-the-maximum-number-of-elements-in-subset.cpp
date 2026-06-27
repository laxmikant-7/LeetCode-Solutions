class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;
        for (int x : nums)
            freq[x]++;
        int ans = 1;
        if (freq.count(1)) {
            int f = freq[1];
            ans = max(ans, (f % 2) ? f : f - 1);
        }
        for (auto &[x, cnt] : freq) {
            if (x == 1) continue;
            long long cur = x;
            int len = 0;

            while (freq.find(cur)!=freq.end() && freq[cur] >= 2) {
                len += 2;
                if (cur > 1e9) break;
                cur = cur * cur;
            }
            if (freq.find(cur)!=freq.end() && freq[cur] == 1){
                ans = max(ans, len + 1);
            }
            else if(freq.find(cur)==freq.end()){
                ans = max(ans, len - 1);
            }
        }
        return ans;
    }
};