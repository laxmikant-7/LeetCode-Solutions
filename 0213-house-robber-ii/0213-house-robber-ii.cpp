class Solution {
public:
    int solve(vector<int> &nums,int i,int n,vector<int> &dp){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int take=nums[i]+solve(nums,i+2,n,dp);
        int skip=solve(nums,i+1,n,dp);
        return dp[i]=max(take,skip);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> dp1(n,-1);
        vector<int> dp2(n,-1);
        int s1=solve(nums,0,n-1,dp1);
        int s2=solve(nums,1,n,dp2);
        return max(s1,s2);
    }
};