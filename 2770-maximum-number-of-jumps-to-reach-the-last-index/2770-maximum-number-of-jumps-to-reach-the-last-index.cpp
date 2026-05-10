class Solution {
public:
    int solve(int i, int t, vector<int>& nums, vector<int>& dp) {
        if (i == nums.size() - 1) return 0;
        if (dp[i] != -2) return dp[i];
        int ans = -1;
        for (int j = i + 1; j < nums.size(); j++) {
            if (abs(nums[j] - nums[i]) <= t) {
                int temp = solve(j, t, nums, dp);
                if (temp != -1) {
                    ans = max(ans, 1 + temp);
                }
            }
        }
        return dp[i] = ans;
    }
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, -2);
        return solve(0, target, nums, dp);
    }
};