class Solution {
public:
    int solve(int i,vector<int> &nums,vector<int> &dp,int n){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int f1=nums[i]+solve(i+2,nums,dp,n);
        int f2=INT_MIN;
        if(i+1<n){
            f2=solve(i+1,nums,dp,n);
        }
        return dp[i]=max(f1,f2);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> dp(n,-1);
        int i=0;
        int c1=solve(i,nums,dp,n-1);
        i=1;
        dp.assign(n, -1);
        int c2=solve(i,nums,dp,n);
        return max(c1,c2);
    }
};