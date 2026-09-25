class Solution {
public:
    long long solve(vector<int>& nums,vector<vector<long long>> &dp,int i,bool isadd){
        if(i>=nums.size()) return 0;
        if(dp[i][isadd]!=1LL*-1) return dp[i][isadd];
        long long skip=solve(nums,dp,i+1,isadd);
        long long val=1LL*nums[i];
        if(!isadd){
            val=-val;
        }
        long long take=solve(nums,dp,i+1,!isadd)+val;
        return dp[i][isadd]=max(skip,take);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<long long>> dp(n,vector<long long>(2,1LL*-1));
        return solve(nums,dp,0,true);
    }
};