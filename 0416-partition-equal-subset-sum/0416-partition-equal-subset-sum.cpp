class Solution {
public:
    bool solve(vector<int>& nums,vector<vector<int>> &dp,int t,int i){
        if(t==0) return true;
        if(i==nums.size()) return t==0;
        if(dp[i][t]!=-1) return dp[i][t];
        bool take=false;
        if(nums[i]<=t){
            take=solve(nums,dp,t-nums[i],i+1);
        }
        bool nontake=solve(nums,dp,t,i+1);
        return dp[i][t]=take||nontake;
    }
    
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int target=0;
        for(auto num:nums){
            target+=num;
        }
        if(target%2==1) return false;
        vector<vector<int>> dp(n,vector<int>((target/2)+1,-1));
        return solve(nums,dp,target/2,0);
    }
};