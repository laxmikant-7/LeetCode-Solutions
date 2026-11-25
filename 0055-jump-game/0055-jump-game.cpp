class Solution {
public:
    bool solve(int i,vector<int> &nums,vector<int> &dp){
        if(i>=nums.size()) return false;
        if(i==nums.size()-1) return true;
        if(dp[i]!=-1) return dp[i];
        for(int add=1;add<=nums[i];add++){
            if(solve(i+add,nums,dp)) return true;
        }
        return dp[i]=false;
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return solve(0,nums,dp);
        
    }
};