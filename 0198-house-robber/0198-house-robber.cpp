class Solution {
public:
    int solve(int i,vector<int> &nums,vector<int> &dp,int n){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int first=nums[i]+solve(i+2,nums,dp,n);
        int second=INT_MIN;
        if(i+1<n){
            second=nums[i+1]+solve(i+3,nums,dp,n);
        }
        return dp[i]=max(first,second);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        int i=0;
        return solve(i,nums,dp,n);
    }
};